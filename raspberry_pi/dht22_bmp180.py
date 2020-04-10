#!/usr/bin/env python

import sys
import traceback
import RPi.GPIO as GPIO
from time import sleep
import Adafruit_DHT
import Adafruit_BMP.BMP085 as BMP085
from urllib.request import urlopen

API_KEY = '****************'

def getDht22SensorData():
    RH, T = Adafruit_DHT.read_retry(Adafruit_DHT.DHT22, 18)
    return (str(RH), str(T))

def main():
    print('Starting...')
    baseUrl = 'https://api.thingspeak.com/update?api_key=%s' % API_KEY
    bmp180Sensor = BMP085.BMP085(mode = BMP085.BMP085_STANDARD)

    while True:
        try:
            rh, t = getDht22SensorData()
            p = str(bmp180Sensor.read_pressure() / 100.0)
            print("SensorData: " + rh + ", " + t + ", " + p)
            f = urlopen(baseUrl + "&field1=%s&field2=%s&field3=%s" % (rh, t, p))
            print(f.read())
            f.close()
            sleep(15 * 60)
        except Exception as e:
            print('Exiting: %s, %s' % (str(e), repr(e)))
            traceback.print_exc()
            #break

if __name__ == '__main__':
    main()
