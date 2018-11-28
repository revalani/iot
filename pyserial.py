import serial # if you have not already done so
import serial
import JSON

ser = serial.Serial('/dev/ttyUSB0', 9600)
while True:
    print(ser.readline().decode('utf-8')
