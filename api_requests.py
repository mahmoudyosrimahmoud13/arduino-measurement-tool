import serial
import requests


ser = serial.Serial('COM7', baudrate=9600)
try:
    while True:
        data = ser.readline().decode('utf-8')
        data = data.split('/')

        print(f"serial got the data: {data}")
        url = f'http://192.168.115.133:45455/api/Embedded?meggint={data[0]}&state={data[1]}'
        response = requests.post(url)
        print("Sucess")

except:
    print("serial stopped")
