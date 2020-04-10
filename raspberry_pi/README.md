# Simple weather station project using Raspberry Pi

Hardware components used:
- Raspberry Pi 3 Model B Rev 1.2
  - `cat /proc/cpuinfo`
  - `cat /sys/firmware/devicetree/base/model`
- DHT22 temperature, humidity sensor
- BMP180 barometric pressure, temperature, altitude sensor
- Breadboard
- A 10 kOhm resistor
- Cables

Raspbian packages needed to run the code:
- python3
- pip3
- i2c-tools (for `i2cdetect`)
- RPi.GPIO (comes as a pip3 package: `sudo pip3 install RPi.GPIO`)
- Adafruit_DHT (comes as a pip3 package: `sudo pip3 install Adafruit_DHT`)
- Adafruit_BMP (comes as a pip3 package: `sudo pip3 install Adafruit_BMP`)

Other settings (`pi` is used as an example user):
- The VCC for the DHT22 can be 3.3 V or 5 V
- A pullup resistor 10 kOhm - 50 kOhm is needed on the data pin of the DHT22
- BMP180 is connected to I2C interface (SDA1, SCL1) on the Raspberry Pi
- The I2C interface needs to be enabled on the Raspberry Pi, e.g. through `raspi-config`
- The user needs to be in the `i2c` group, if not `sudo usermod -a -G i2c pi`
- To verify if the I2C is properly setup `i2cdetect -y 1`
- The user needs to be in the `gpio` group, if not `sudo usermod -a -G gpio pi`
- To check if the groups are OK `groups pi`
- To start the script automatically:
  - `sudo crontab -e` (should work without all the `sudo`s too)
  - Add the line `@reboot sudo python3 /home/pi/dht22_bmp180.py 2>&1 >/tmp/dht22_bmp180.log`

The script is posting three numbers (the three measurements) in every 15 minutes to ThingSpeak:
- Temperature from DHT22 in °C
- Humidity from DHT22 in %
- Barometric pressure from BMP180 in hPa
