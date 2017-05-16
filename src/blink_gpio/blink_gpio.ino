#define LED 2

long tempoArray[] = {50, 100, 15, 1200};
int tempoIndex = 1;

long prevMillis = 0;

void setup() {
  pinMode(LED, OUTPUT);

  Serial.begin(115200);
  Serial.print("\nHello world!!!\n");
}

void loop() {
  heartBeat(1.0);
}

void heartBeat(float tempo) {
  if ((millis() - prevMillis) > tempoArray[tempoIndex]*tempo) {

    if (++tempoIndex > 3) {
      tempoIndex = 0;
      Serial.print(".");
    }

    if (!(tempoIndex % 2)) {
      digitalWrite(LED, LOW);
      delay(tempoArray[tempoIndex]) ;
      digitalWrite(LED, HIGH);
    }

    tempoIndex++;
    prevMillis = millis();
  }
}

