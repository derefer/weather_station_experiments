/*
   Field 1 temp DHT22
   Field 2 humidity DHT22
   Field 3 Airpressure BMP180
*/
#include <DHT.h>
#include <Adafruit_BMP085.h>
#include <Wire.h>
#include <ESP8266WiFi.h>

#define DHTPIN 1 // GPIO1 (TX)
#define DHTTYPE DHT22

const char* ssid     = "SSID";
const char* password = "PASSWORD";
const char* host = "api.thingspeak.com";

const char* writeAPIKey = "APIKEY";

DHT dht(DHTPIN, DHTTYPE);
Adafruit_BMP085 bmp;

void setup()
{
    Wire.pins(0, 2);
    Wire.begin(0, 2);
    dht.begin();
    bmp.begin();

    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
    }
}

void loop()
{
    float humidity = dht.readHumidity();
    float temperature = dht.readTemperature();
    if (isnan(humidity) || isnan(temperature)) {
        return;
    }
    int32_t pressure = bmp.readPressure() / 100; // Pa -> hPa

    WiFiClient client;
    const int httpPort = 80;
    if (!client.connect(host, httpPort)) {
        return;
    }

    String url = "/update?key=";
    url += writeAPIKey;
    url += "&field1=";
    url += String(temperature); // DHT22
    url += "&field2=";
    url += String(humidity); // DHT22
    url += "&field3=";
    url += String(pressure); // BMP180
    url += "\r\n";

    client.print(String("GET ") + url + " HTTP/1.1\r\n" +
                 "Host: " + host + "\r\n" +
                 "Connection: close\r\n\r\n");

    delay(60 * 1000);
}
