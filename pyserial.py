import serial # if you have not already done so
ser = serial.Serial('/dev/tty.usbserial', 9600) # alterar porta e permicoes 
ser.write(b'5')


