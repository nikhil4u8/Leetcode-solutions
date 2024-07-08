//TIME - o(NlogN) SPACE - O(N)
import csv
from math import sqrt

# Define a function to calculate speed
def calculate_speed(leg_length, stride_length):
    return ((stride_length / leg_length) - 1) * sqrt(leg_length * g)
    
if __name__ == "__main__":
    file1 = "file1.csv"
    file2 = "file2.csv"
    # Define the gravitational constant
    g = 9.8

    # Define a function to calculate speed
    def calculate_speed(leg_length, stride_length):
        return ((stride_length / leg_length) - 1) * sqrt(leg_length * g)

    # Initialize dictionaries to store dinosaur data
    dino_data1 = {}
    dino_data2 = {}

    # Read data from file1.csv
    try:
        with open('file1.csv', mode='r') as file1:
            csv_reader = csv.DictReader(file1)
            for row in csv_reader:
                try:
                    name = row['NAME']
                    leg_length = float(row.get('LEG_LENGTH', 0))
                    diet = row.get('DIET', '')
                    dino_data1[name] = {
                        'LEG_LENGTH': leg_length,
                        'DIET': diet
                    }
                except KeyError:
                    print("Error: Missing or incorrect column in file1.csv")

    except FileNotFoundError:
        print("Error: file1.csv not found")

    # Read data from file2.csv
    try:
        with open('file2.csv', mode='r') as file2:
            csv_reader = csv.DictReader(file2)
            for row in csv_reader:
                try:
                    name = row['NAME']
                    stride_length = float(row.get('STRIDE_LENGTH', 0))
                    stance = row.get('STANCE', '')
                    dino_data2[name] = {
                        'STRIDE_LENGTH': stride_length,
                        'STANCE': stance
                    }
                except KeyError:
                    print("Error: Missing or incorrect column in file2.csv")

    except FileNotFoundError:
        print("Error: file2.csv not found")

    # Create a list to store bipedal dinosaurs and their speeds
    bipedal_dinos = []

    # Iterate through the dinosaurs in both datasets and calculate speed for bipedal dinosaurs
    for name in dino_data1.keys():
        if name in dino_data2 and dino_data2[name]['STANCE'] == 'bipedal':
            speed = calculate_speed(dino_data1[name]['LEG_LENGTH'], dino_data2[name]['STRIDE_LENGTH'])
            bipedal_dinos.append((speed, name))

    # Sort bipedal dinosaurs by speed (fastest to slowest)
    bipedal_dinos.sort(reverse=True)

    # Print the names of bipedal dinosaurs sorted by speed
    for speed, name in bipedal_dinos:
        print(name)
