##############
## Script listens to serial port and writes contents into a file
#############
## https://electronics.stackexchange.com/questions/54/saving-arduino-sensor-data-to-a-text-file
## requires pySerial to be installed
## sudo -H pip3 install pyserial
import serial

serial_port = '/dev/ttyACM0';# (Arduino/Genuino Mega or Mega 2560)';
baud_rate = 9600; #In arduino, Serial.begin(baud_rate)
SERIAL_DATA_FILE = "output.txt";

# Write file
#output_file = open(write_to_file_path, "w+");
output_file = open(SERIAL_DATA_FILE, "w");
ser = serial.Serial(serial_port, baud_rate)
num_captures = 10
while num_captures > 0:
    line = ser.readline();
    line = line.decode("utf-8", "strict") #ser.readline returns a binary, convert to string
    print(line)
    print(num_captures)
    try:
        num = float(line)
        print(num)
        numstr = str(num)
        output_file.write(line)
        num_captures -= 1
    except:
        print('Error')
ser.close()
output_file.close()
ent = input("Presione una tecla para leer el archivo")

# Read file
import numpy as np
from numpy import genfromtxt

data = np.genfromtxt(SERIAL_DATA_FILE)
print(data)
