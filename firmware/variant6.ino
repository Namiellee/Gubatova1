#include <DHT.h>
#define DHTPIN 2
#define DHTTYPE DHT22
#define PIR_PIN 3
#define BUZZER_PIN 4
#define LED_PIN 5
#define NTC_PIN A0
#define T_MS 2000
#define THRESHOLD_HUMIDITY 70.0
DHT dht(DHTPIN, DHTTYPE);
int n = 0;
bool thresholdActive = false;
void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(PIR_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, LOW);
  digitalWrite(LED_PIN, LOW);
}
double readNTC() {
  int raw = analogRead(NTC_PIN);
  return 0.0 + (50.0 - 0.0) * raw / 1023.0;
}
void loop() {
  n++;
  double s1 = readNTC();
  double s2 = dht.readHumidity();
  int s3 = digitalRead(PIR_PIN);
  if (isnan(s1)) s1 = 0.0;
  if (isnan(s2)) s2 = 0.0;
  Serial.print("DATA n=");
  Serial.print(n);
  Serial.print(" s1=");
  Serial.print(s1, 2);
  Serial.print(" s2=");
  Serial.print(s2, 2);
  Serial.print(" s3=");
  Serial.println(s3);
  if (s2 > THRESHOLD_HUMIDITY) {
    if (!thresholdActive) {
      digitalWrite(BUZZER_PIN, HIGH);
      digitalWrite(LED_PIN, HIGH);
      Serial.print("EVENT n=");
      Serial.print(n);
      Serial.println(" type=THRESHOLD");
      thresholdActive = true;
    }
  } else {
    if (thresholdActive) {
      digitalWrite(BUZZER_PIN, LOW);
      digitalWrite(LED_PIN, LOW);
      Serial.print("EVENT n=");
      Serial.print(n);
      Serial.println(" type=NORMAL");
      thresholdActive = false;
    }
  }
  delay(T_MS);
}