// Blink the blue built-in LED on ESP8266-01
const uint32_t GPIO = 1;

void setup()
{
    pinMode(GPIO, OUTPUT);
}

void loop()
{
    digitalWrite(GPIO, HIGH);
    delay(1000); // 1s (ms)
    digitalWrite(GPIO, LOW);
    delay(1000); // 1s (ms)
}
