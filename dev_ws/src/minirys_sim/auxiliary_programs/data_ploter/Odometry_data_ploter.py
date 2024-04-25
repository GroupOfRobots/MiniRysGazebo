import os
import matplotlib.pyplot as plt
import math
import numpy as np

def quaternion_to_euler(x, y, z, w):
    """
    Convert a quaternion into euler angles (roll, pitch, yaw)
    roll is rotation around x in radians (counterclockwise)
    pitch is rotation around y in radians (counterclockwise)
    yaw is rotation around z in radians (counterclockwise)
    """
    t0 = +2.0 * (w * x + y * z)
    t1 = +1.0 - 2.0 * (x * x + y * y)
    roll_x = math.atan2(t0, t1)
    
    t2 = +2.0 * (w * y - z * x)
    t2 = +1.0 if t2 > +1.0 else t2
    t2 = -1.0 if t2 < -1.0 else t2
    pitch_y = math.asin(t2)
    
    t3 = +2.0 * (w * z + x * y)
    t4 = +1.0 - 2.0 * (y * y + z * z)
    yaw_z = math.atan2(t3, t4)

    return roll_x, pitch_y, yaw_z

def parse_ros2_message(file_path):
    with open(file_path, 'r') as file:
        lines = file.readlines()

    if not lines:
        print(f"No data in file {file_path}")
        return [], []

    timestamps = []
    angular_positions = []
    temp_sec = None
    temp_nsec = None
    x, y, z, w = None, None, None, None
    orientation_section = False
    stamp_section = False
    sec_not_recorded_flag = True

    for line in lines:
        line = line.strip()
        if 'stamp:' in line:
            stamp_section = True
            sec_not_recorded_flag = True
        elif 'frame_id:' in line:
            stamp_section = False
        elif 'orientation:' in line:
            orientation_section = True
        elif 'position:' in line:
            orientation_section = False

        if sec_not_recorded_flag and stamp_section and 'sec:' in line:
            temp_sec = int(line.split(': ')[1].strip())
            sec_not_recorded_flag = False
        elif (not sec_not_recorded_flag) and stamp_section and 'nanosec:' in line:
            temp_nsec = int(line.split(': ')[1].strip())
            stamp_section = False
        elif orientation_section and 'x:' in line:
            x = float(line.split(': ')[1].strip())
        elif orientation_section and 'y:' in line:
            y = float(line.split(': ')[1].strip())
        elif orientation_section and 'z:' in line:
            z = float(line.split(': ')[1].strip())
        elif orientation_section and 'w:' in line:
            w = float(line.split(': ')[1].strip())
            orientation_section = False
            if temp_sec is not None and temp_nsec is not None:
                if len(timestamps) == 0:
                    start_time = temp_sec
                timestamp = temp_sec - start_time + temp_nsec / 1e9
                timestamps.append(timestamp)
                roll, pitch, yaw = quaternion_to_euler(x, y, z, w)
                angular_position = pitch
                angular_positions.append(math.degrees(angular_position))
                temp_sec, temp_nsec, x, y, z, w = None, None, None, None, None, None
            else:
                print(f"temp_sec {temp_sec}, temp_nsec {temp_nsec}, x {x}, y {y}, z {z}, w {w}")
        

    if len(timestamps) != len(angular_positions):
        print(f"Warning: Mismatch in data lengths for file {file_path}. Timestamps: {len(timestamps)}, Angular Positions: {len(angular_positions)}")

    return timestamps, angular_positions

def save_processed_data(timestamps, angular_positions, file_name):
    with open(f'processed_data/data_{file_name}.txt', 'w') as file:
        for x, y in zip(timestamps, angular_positions):
            file.write(f'{x} {y}\n')

def plot_data(timestamps, angular_positions, file_name):
    start_time = None
    end_time = None

    for i, value in enumerate(angular_positions):
        if abs(value) >= 20 and start_time is None:
            start_time = timestamps[i] - 5
            break

    for i, value in enumerate(angular_positions):
        if abs(value) >= 70 and end_time is None:
            end_time = timestamps[i] + 5
            break

    plt.figure()
    plt.plot(timestamps, angular_positions)
    plt.xlabel('Time (seconds)')
    plt.ylabel('Angular Position (degrees)')

    title = file_name

    plt.title(f"{title} - change_time = {round(end_time - start_time - 10, 5)}")

    if start_time is not None and end_time is not None:
        plt.xlim(start_time, end_time)
        print(f"File: {file_name}, Start Time: {start_time}, End Time: {end_time}")
    else:
        print(f"File: {file_name}, Start or End Time not found.")

    plt.savefig(f'plots/{file_name}.png')
    plt.close()


def process_folder(folder_path):
    for file_name in os.listdir(folder_path):
        if file_name.endswith('.txt'):
            file_path = os.path.join(folder_path, file_name)
            new_file_name = file_name.replace(".txt", "")
            timestamps, angular_positions = parse_ros2_message(file_path)
            save_processed_data(timestamps, angular_positions, new_file_name)
            plot_data(timestamps, angular_positions, new_file_name)


def main():
    process_folder('raw_data')

if __name__ == "__main__":
    main()