from PIL import Image, ImageChops
import xml.etree.ElementTree as ET
import os
import re
import pathlib


def is_yellow(pixel):
    r, g, b, a = pixel
    return 30 <= r <= 255 and 30 <= g <= 255 and 0 <= b <= 25

def isolate_yellow(img):
    img_data = img.load()
    for y in range(img.height):
        for x in range(img.width):
            if is_yellow(img_data[x, y]):
                continue
            else:
                img_data[x, y] = (0, 0, 0, 0)
    return img

def delete_yellow(img):
    img_data = img.load()
    for y in range(img.height):
        for x in range(img.width):
            if is_yellow(img_data[x, y]):
                img_data[x, y] = (0, 0, 0, 0)
            else:
                continue
    return img

def normalize_pixels(img):
    img_data = img.load()

    # Find the brightest pixel
    max_brightness = 0
    for y in range(img.height):
        for x in range(img.width):
            r, g, b, a = img_data[x, y]
            if a == 0:  # Ignore transparent pixels
                continue
            brightness = max(r, g, b)
            if brightness > max_brightness:
                max_brightness = brightness

    # print(f"max_brightness = {max_brightness}")

    # Normalize the image
    for y in range(img.height):
        for x in range(img.width):
            r, g, b, a = img_data[x, y]
            if a == 0:  # Ignore transparent pixels
                continue
            img_data[x, y] = (
                int(r / max_brightness * 255),
                int(g / max_brightness * 255),
                int(b / max_brightness * 255),
                a,
            )
    return img

def convert_to_greyscale_with_alpha(img):
    if img.mode == "RGBA":
        grey = img.convert("L")  
        a = img.split()[3]  
        grey.putalpha(a)  
        return grey
    else:
        return img.convert("L")

def multiply_images(image1, image2):
    return ImageChops.multiply(image1, image2)

def add_images(image1, image2):
    return ImageChops.add(image1, image2)

def generate_solid_color_image(width, height, color):
    color_255 = tuple(int(c) for c in color[:3]) + (255,)
    return Image.new("RGBA", (width, height), color_255)

def parse_xml_to_colors(file_path):
    tree = ET.parse(file_path)
    root = tree.getroot()

    robot_color_name = []
    robot_RGB = []
    robot_options_name_list  = {"color_code": str, 
                                "color_code_R": float, 
                                "color_code_G": float, 
                                "color_code_B": float, 
                                "color_code_A": float}

    for option_name, option_type in robot_options_name_list.items():
        element = root.find(option_name)
        if element is not None:
            value = element.text
            if option_type == float:
                robot_RGB.append(float(value)) 
            elif option_type == str:
                robot_color_name = str(value)
    # print(robot_color_name, robot_RGB)
    return robot_color_name, robot_RGB

def atoi(text):
    return int(text) if text.isdigit() else text

def natural_keys(text):
    return [atoi(c) for c in re.split(r'(\d+)', text)]

def load_data(robot_config_path):
    robot_color_name_list = []
    robot_RGB_list = []

    file_list = sorted(os.listdir(robot_config_path), key=natural_keys)
    # print(file_list)
    for idx, file in enumerate(file_list):
        if re.match(r"^robot\d+_config.xml$", file):
            print(f"Loading color data form {file}")
            file_path = os.path.join(robot_config_path, file)
            robot_color_name, robot_RGB = parse_xml_to_colors(file_path)
            robot_color_name_list.append(robot_color_name)
            robot_RGB_list.append(robot_RGB)

    return robot_color_name_list, robot_RGB_list

def crop_sides(img, left_crop, right_crop, top_crop, bottom_crop):
    width, height = img.size
    left = left_crop
    upper = top_crop
    right = width - right_crop
    lower = height - bottom_crop
    return img.crop((left, upper, right, lower))

def delete_missing(folder_path, robot_color_name_list):
    folder_list = []
    for robot in robot_color_name_list:
        folder_list.append(f"{robot}_robot.png")
    
    if os.path.isdir(folder_path):
    # List all files in the folder
        files = os.listdir(folder_path)

        for idx, file in enumerate(files):
            file_path = os.path.join(folder_path, file)

            if os.path.isfile(file_path):
                if file not in folder_list:
                    os.remove(file_path)
                    robot_color_name = file.replace("_robot.png", "")
                    print(f"Color {robot_color_name} outdated, deleting...")
            else:
                print(f'{file_path} is not a file.')

def check_image_exists(result_path, image_name):
    return pathlib.Path(os.path.join(result_path, image_name)).is_file()

def load_or_generate_image(file_path, generate_func, *args, **kwargs):
    if check_image_exists(file_path.parent, file_path.name):
        print(f"Loading existing image: {file_path}")
        return Image.open(file_path).convert("RGBA")
    else:
        img = generate_func(*args, **kwargs)
        img.save(file_path)
        return img
    
if __name__ == "__main__":
    package_path = os.path.abspath(__file__).replace("APP/robot_colored/image_generator.py", "")
    input_image_path = f"{package_path}/APP/robot_colored/input.png"
    print("\n##################### IMAGE GENERATION STARTED #####################")
    print("#### PROCESSING DATA...")
    img = Image.open(input_image_path).convert("RGBA")
    width, height = img.size
    
    output_directory_path = pathlib.Path(package_path) / "APP" / "robot_colored" / "output"
    if not output_directory_path.exists():
        output_directory_path.mkdir(parents=True)

    img_shadows = load_or_generate_image(output_directory_path / "shadows.png", isolate_yellow, img.copy())
    img_mask = load_or_generate_image(output_directory_path / "mask.png", delete_yellow, img.copy())

    greyscale_image = load_or_generate_image(output_directory_path / "greyscale_shadows.png", convert_to_greyscale_with_alpha, img_shadows)
    img_normalized = load_or_generate_image(output_directory_path / "normalized_shadows.png", normalize_pixels, greyscale_image.convert("RGBA"))
    
    robot_color_name_list, robot_RGB_list = load_data(f"{package_path}config/robots/")
    folder_path = f"{package_path}/APP/robot_colored/robots"
    delete_missing(folder_path, robot_color_name_list)

    colored_images = []
    for i in range(len(robot_RGB_list)):
        img = generate_solid_color_image(width, height, robot_RGB_list[i])
        # img.save(f"output/{robot_color_name_list[i]}_solid.png")
        colored_images.append(img)
    
    
    result_path = f"{package_path}/APP/robot_colored/robots"
    if not os.path.exists(result_path):
        os.makedirs(result_path)

    print("#### GENERATING IMAGES...")
    for i in range(len(colored_images)):
        output_image_name = f"{robot_color_name_list[i]}_robot.png"
        
        if check_image_exists(result_path, output_image_name):
            print(f"Image {output_image_name} already exists, skipping...")
            continue
        
        multiplied_img = multiply_images(img_normalized, colored_images[i])
        final_img = add_images(multiplied_img, img_mask)
        # multiplied_img.save(f"output/{robot_color_name_list[i]}_multiplied.png")
        # final_img.save(f"output/{robot_color_name_list[i]}_final.png")
        cropped_image = crop_sides(final_img, 300, 300, 0, 0)
        cropped_image.save(os.path.join(result_path, output_image_name))
    print("##################### IMAGE GENERATION COMPLETED #####################\n")