#define BLYNK_TEMPLATE_ID           "TMPLVOlHlkey"
#define BLYNK_DEVICE_NAME           "Quickstart Device"
#define BLYNK_AUTH_TOKEN            "cN_2zPno9nDY9gLR9o-FvN6I1aWJVJDu"


// Comment this out to disable prints and save space
#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN;

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Quang Huy";
char pass[] = "hettienroiban";

BlynkTimer timer;

BLYNK_WRITE(V0)
{
  int value = param.asInt();
  digitalWrite(0, value);
}

BLYNK_CONNECTED()
{
}

void setup()
{
  Serial.begin(115200);

  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  Blynk.run();
}