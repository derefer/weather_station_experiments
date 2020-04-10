# Simple weather station project using Raspberry Pi

Hardware components used:
- Raspberry Pi 3 Model B Rev 1.2
- DHT22 temperature, humidity sensor
- BMP180 barometric pressure, temperature, altitude sensor
- Breadboard
- A 10 kOhm resistor
- Cables

Good to know:
- VCC for DHT22 can be 3-5 V
- Pullup resistor value can be 10-50 kOhm
- BMP180 is connected to I2C (SDA1, SCL1) on the Raspberry Pi, probably that's the default setting in the library
- The I2C interface needs to be enabled on the Raspberry Pi, e.g. through `raspi-config`
- The user needs to be in the i2c group, if not `sudo usermod -a -G i2c pi`
- To verify if the I2C is properly setup:
  `i2cdetect -y 1` should output something like:
`       0  1  2  3  4  5  6  7  8  9  a  b  c  d  e  f
00:          -- -- -- -- -- -- -- -- -- -- -- -- -- 
10: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- 
20: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- 
30: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- 
40: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- 
50: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- 
60: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- 
70: -- -- -- -- -- -- -- 77`  `
- The user needs to be in the gpio group, if not `sudo usermod -a -G gpio pi`
