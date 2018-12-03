# from time import *
import serial
# import urllib2
# from datetime import datetime

# previsao = urllib2.urlopen('http://api.openweathermap.org/data/2.5/weather?id=3451190&appid=79eccc6a51de31f8d81332dbc05448cd')


ser = serial.Serial('/dev/ttyUSB0', 9600) # Establish the connection on a specific port
# time = datetime.now() # Below 32 everything in ASCII is gibberish

lista={}
a=5
while a!=0:
	print (ser.readline().decode('utf-8')) # Convert the decimal number to ASCII then send it to the Arduino
	# a-=1
	# print (str(time), ser.readline().decode('utf-8')) 
	# lista.apped(time=str(time),temp=ser.readline().decode('utf-8'))#, "temp":ser.readline().decode('utf-8'))

# print previsao