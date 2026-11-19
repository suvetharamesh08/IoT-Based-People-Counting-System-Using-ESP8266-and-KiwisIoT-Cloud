#include <ESP8266WiFi.h>
#include <KiwisIoT.h>

// WiFi credentials
const char* ssid = "YOUR_WIFI_NAME";
const char* pass = "YOUR_WIFI_PASSWORD";

// KiwisIoT Topic ID
const char* topic = "YOUR_TOPIC_ID";

// KiwisIoT object
KiwisIoT kiwisiot(ssid, pass, topic);

// IR sensors
int entrance = D2;
int exitSensor = D3;

// LEDs
int yellow = D6;
int green = D7;

// People count
int entrancecount = 0;
int exitcount = 0;
int people = 0;

void setup() {
  Serial.begin(115200);

  pinMode(entrance, INPUT);
  pinMode(exitSensor, INPUT);

  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);

  kiwisiot.begin();
}

void loop() {
  kiwisiot.run();

  // Person entering
  if (digitalRead(entrance) == LOW) {
    entrancecount++;
    people++;

    Serial.print("Count in: ");
    Serial.println(entrancecount);

    Serial.print("People Inside: ");
    Serial.println(people);

    digitalWrite(yellow, HIGH);
    delay(300);
    digitalWrite(yellow, LOW);

    kiwisiot.send("0", entrancecount);

    while (digitalRead(entrance) == LOW) {
      delay(50);
    }
  }

  // Person exiting
  if (digitalRead(exitSensor) == LOW) {
    exitcount++;

    if (people > 0) {
      people--;
    }

    Serial.print("Count out: ");
    Serial.println(exitcount);

    Serial.print("People Inside: ");
    Serial.println(people);

    digitalWrite(green, HIGH);
    delay(300);
    digitalWrite(green, LOW);

    kiwisiot.send("1", exitcount);

    while (digitalRead(exitSensor) == LOW) {
      delay(50);
    }
  }

  delay(100);
}
