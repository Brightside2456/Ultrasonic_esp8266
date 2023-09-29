
#define BLYNK_PRINT Serial

/* Fill in information from Blynk Device Info here */
#define BLYNK_TEMPLATE_ID "TMPL2TMZD_kGn"
#define BLYNK_TEMPLATE_NAME "ReadingVals"
#define BLYNK_AUTH_TOKEN "6nufah93nvto6KerLtiDfQKcidmhqNR3"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

BlynkTimer timer;

#define trigpin D3
#define echopin D2
int duration;
int distance_cm;


void sendDistance()
{
    digitalWrite(trigpin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigpin, LOW);
  duration = pulseIn(echopin, HIGH);

  distance_cm = ((duration * 0.032) / 2);
  Serial.println(distance_cm);

  Blynk.virtualWrite(V5, distance_cm);
}

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Galaxy A038747";
char pass[] = "skte45555";


void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  //Setup Sensor pins
  timer.setInterval(1000L, sendDistance);

  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

}

void loop() {
  Blynk.run();
  timer.run();
}
