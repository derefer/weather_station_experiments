void setup()
{
    Serial.begin(115200);
    Serial.setTimeout(2000);
    delay(100);
    while (!Serial) {}
    // Deep sleep for 10s
    // For ESP8266-01 soldering is needed
    // The ESP8266-12E wakes up by itself when GPIO16 (D0 on the NodeMcu) is connected to the RST pin
    Serial.println("I'm awake, but I'm going into deep sleep mode for 10 seconds");
    ESP.deepSleep(10e6);

    //Deep sleep mode until RST pin is connected to a LOW signal (for example pushbutton or magnetic reed switch)
    //Serial.println("I'm awake, but I'm going into deep sleep mode until RST pin is connected to a LOW signal");
    //ESP.deepSleep(0);
}

void loop()
{
    // This will never be executed
}
