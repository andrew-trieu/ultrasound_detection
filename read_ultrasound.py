import serial
# import time
# import schedule
# import json

def read_arduino_data(port: str):
    connection = serial.Serial(port=port, baudrate=9600)
    print('Established serial connection to Arduino')
    arduino_data = connection.readline().decode("UTF-8")
    
    data = []
    data_split = arduino_data.split(',')
    for d in data_split:
        data.append(float(d))
    # data[data] = float(data_split[1])

    # data_split = arduino_data.split(",")
    # float_data = []

    # for i in range(len(data_split)):
    #     float_data.append(float(data_split[i]))
    # cleaned = data_split.replace("\r\n","")

    return data

port = 'COM10'
for i in range(5):
    print(read_arduino_data(port))