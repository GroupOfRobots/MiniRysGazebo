import os
import matplotlib.pyplot as plt
import math
import re

def parse_ros2_message(file_path):
    with open(file_path, 'r') as file:
        lines = file.readlines()

    timestamps = []
    angular_positions = []
    temp_sec = None
    temp_nsec = None

    for line in lines:
        if ' sec:' in line:
            temp_sec = int(line.split(': ')[1].strip())
        elif 'nanosec:' in line:
            temp_nsec = int(line.split(': ')[1].strip())
            if temp_sec is not None and temp_nsec is not None:
                if len(timestamps) == 0:
                    start_time = temp_sec
                timestamp = temp_sec - start_time + temp_nsec / 1e9
                timestamps.append(timestamp)
                temp_sec = None
                temp_nsec = None
        elif 'angular_position:' in line:
            angular_position = float(line.split(': ')[1].strip())
            angular_position_degrees = math.degrees(angular_position)  # Convert to degrees
            angular_positions.append(angular_position_degrees)

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

    if len(file_name) > 16:
        title = file_name[:-16] 
    else:
        title = file_name

    plt.title(f"{title} - change_time = {round(end_time - start_time - 10, 5)}")

    if start_time is not None and end_time is not None:
        plt.xlim(start_time, end_time)
        print(f"File: {file_name}, Start Time: {start_time}, End Time: {end_time}")
    else:
        print(f"File: {file_name}, Start or End Time not found.")

    plt.savefig(f'plots/{file_name}.png')
    plt.close()
    if start_time is not None and end_time is not None:
        change_time = round(end_time - start_time - 10, 5)
        return title, change_time
    else:
        return title, None

def process_folder(folder_path):
    change_times = []

    for file_name in os.listdir(folder_path):
        if file_name.endswith('.txt'):
            file_path = os.path.join(folder_path, file_name)
            new_file_name = file_name.replace(".txt", "")
            timestamps, angular_positions = parse_ros2_message(file_path)
            save_processed_data(timestamps, angular_positions, new_file_name)
            title, change_time = plot_data(timestamps, angular_positions, new_file_name)

            if change_time is not None:
                change_times.append((title, change_time))

    change_times.sort(key=lambda x: int(re.search(r'test(\d+)', x[0]).group(1)))

    with open('change_times_summary.txt', 'w') as file:
        for title, change_time in change_times:
            file.write(f'{title} {change_time}\n')

def main():
    process_folder('raw_data')

if __name__ == "__main__":
    main()