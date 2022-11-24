#define BLYNK_TEMPLATE_ID           "TMPLVOlHlkey"
#define BLYNK_DEVICE_NAME           "Smart Switchboard"
#define BLYNK_AUTH_TOKEN            "cN_2zPno9nDY9gLR9o-FvN6I1aWJVJDu"
#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

const unsigned char TIMER_VIRTUAL_PIN = V0;

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Huy Quang";
char pass[] = "hettienroiban";

BlynkTimer timer;

void uptimeTimerEvent() {
  Blynk.virtualWrite(TIMER_VIRTUAL_PIN, millis() / 1000);
}

BLYNK_CONNECTED() {
  Serial.println("Blynk connected!");
}

void setup() {
  Serial.begin(115200);

  Blynk.begin(auth, ssid, pass);
  timer.setInterval(1000L, uptimeTimerEvent);
}

void loop() {
  Blynk.run();
}
