#define BLYNK_TEMPLATE_ID           "TMPLVOlHlkey"
#define BLYNK_DEVICE_NAME           "Smart Switchboard"
#define BLYNK_AUTH_TOKEN            "cN_2zPno9nDY9gLR9o-FvN6I1aWJVJDu"
#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define GPIO0_VIRTUAL_PIN V0
#define UPTIME_VIRTUAL_PIN V1
#define LIGHTS_TIMEOUT_VIRTUAL_PIN V2

const byte GPIO0_DIGITAL_PIN = 0;

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Quang Huy";
char pass[] = "hettienroiban";
long lightsTimeout = 0;

BlynkTimer timer;

void everySecondTimerEvent() {
  Blynk.virtualWrite(UPTIME_VIRTUAL_PIN, millis() / 1000);

  if (lightsTimeout > 0 && --lightsTimeout == 0) {
    Blynk.virtualWrite(LIGHTS_TIMEOUT_VIRTUAL_PIN, 0);
    if (digitalRead(GPIO0_DIGITAL_PIN) == LOW) {
      return;
    }
    Blynk.virtualWrite(GPIO0_VIRTUAL_PIN, 0);
  }
}

BLYNK_WRITE(GPIO0_VIRTUAL_PIN) {
  Serial.println(param.asInt());
  digitalWrite(GPIO0_DIGITAL_PIN, param.asInt());
}

BLYNK_WRITE(LIGHTS_TIMEOUT_VIRTUAL_PIN) {
  lightsTimeout = param.asLong();
}

BLYNK_CONNECTED() {
  Serial.println("Blynk connected!");
}

void setup() {
  pinMode(GPIO0_DIGITAL_PIN, OUTPUT);
  Serial.begin(115200);

  Blynk.begin(auth, ssid, pass);
  timer.setInterval(1000L, everySecondTimerEvent);
}

void loop() {
  Blynk.run();
  timer.run();
}
