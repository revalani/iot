import serial
import json
import datetime
import urllib.request

with urllib.request.urlopen(link) as response:
   json = json.loads(response.read().decode('utf-8'))
# parametros da API em https://openweathermap.org/current#JSON 
temp = json['main']['temp']

# time = datetime.datetime.now() 
time = datetime.datetime(2018,3,15,7,0,0)
time = datetime.datetime.strftime(time,"%H:%M:%S %d/%m/%Y")# hr,min,sec,day,month,yr

agenda = json.loads(open("agenda.json","r").read())

tempo = {"time":time}
temp  = {"temp":temp}
agenda.update(tempo)
agenda.update(temp)

print (agenda)

# receber do arduino
# lista={}

ser = serial.Serial('/dev/ttyUSB0', 9600) # Establish the connection on a specific port
while True:
	print (ser.readline().decode('utf-8')) # Convert the decimal number to ASCII then send it to the ArduinoJson.h
