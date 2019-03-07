// Blink the blue built-in LED on ESP8266-01 with deep sleep
const uint32_t GPIO = 1;

void setup()
{
    pinMode(GPIO, OUTPUT);
    digitalWrite(GPIO, HIGH);
    delay(1000); // 1s (ms)
    digitalWrite(GPIO, LOW);
    ESP.deepSleep(10e6); // 10s (us)
}

void loop()
{
}
