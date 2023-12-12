import serial
import requests


ser = serial.Serial('COM6', baudrate=9600)
try:
    while True:
        data = ser.readline().decode('utf-8')
        data = data.split('/')
        print(data[0])
        print(data[1])

except:
    print("serial stopped")
finally:
    serial.close()
