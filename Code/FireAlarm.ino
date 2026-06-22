/*
=========================================================
 SMART GSM FIRE ALARM SYSTEM
 Developer : Harsh Rathore
 Platform  : Arduino UNO
 Sensor    : MQ2 Gas Sensor
 Simulation: Wokwi
 Version   : 1.0
=========================================================
*/

const int MQ2_PIN = A0;
const int LED_PIN = 8;
const int BUZZER_PIN = 9;
const int RESET_BUTTON = 2;

const int SAFE_LEVEL = 300;
const int FIRE_LEVEL = 700;

bool smsSent = false;
int fireCount = 0;

void setup() {

  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(RESET_BUTTON, INPUT_PULLUP);

  Serial.begin(9600);

  Serial.println("=======================================");
  Serial.println(" SMART GSM FIRE ALARM SYSTEM");
  Serial.println("=======================================");
  Serial.println(" Developer : Harsh Rathore");
  Serial.println(" Platform  : Arduino UNO");
  Serial.println(" Sensor    : MQ2 Gas Sensor");
  Serial.println(" Version   : 1.0");
  Serial.println(" Simulation: Wokwi");
  Serial.println("=======================================");
  Serial.println();

}

void loop() {

  int smokeValue = analogRead(MQ2_PIN);
  int smokePercent = map(smokeValue, 0, 1023, 0, 100);

  Serial.println("--------------------------------------");
  Serial.print("Smoke Level      : ");
  Serial.println(smokeValue);

  Serial.print("Smoke Percentage : ");
  Serial.print(smokePercent);
  Serial.println("%");

  if (smokeValue < SAFE_LEVEL) {

    safeMode();

  }
  else if (smokeValue < FIRE_LEVEL) {

    warningMode();

  }
  else {

    fireMode(smokeValue, smokePercent);

  }

  delay(1000);

}

void safeMode() {

  digitalWrite(LED_PIN, LOW);
  noTone(BUZZER_PIN);

  smsSent = false;

  Serial.println("[SAFE]");
  Serial.println();

}

void warningMode() {

  digitalWrite(LED_PIN, HIGH);
  delay(150);
  digitalWrite(LED_PIN, LOW);

  noTone(BUZZER_PIN);

  Serial.println("[WARNING]");
  Serial.println();

}

void fireMode(int smokeValue, int smokePercent) {

  digitalWrite(LED_PIN, HIGH);
  tone(BUZZER_PIN, 1000);

  Serial.println("[CRITICAL FIRE]");

  if (!smsSent) {

    fireCount++;

    sendSMS(smokeValue, smokePercent);

    smsSent = true;

  }

  if (digitalRead(RESET_BUTTON) == LOW) {

    digitalWrite(LED_PIN, LOW);
    noTone(BUZZER_PIN);

    Serial.println("Alarm Reset");

  }

  Serial.println();

}

void sendSMS(int smokeValue, int smokePercent) {

  Serial.println();
  Serial.println("----------- GSM MODULE ------------");

  Serial.println("AT");
  Serial.println("OK");

  Serial.println("AT+CMGF=1");
  Serial.println("OK");

  Serial.println("AT+CMGS=\"+919876543210\"");
  Serial.println(">");

  Serial.println("***** FIRE ALERT *****");

  Serial.print("Smoke Level : ");
  Serial.println(smokeValue);

  Serial.print("Smoke Percentage : ");
  Serial.print(smokePercent);
  Serial.println("%");

  Serial.print("Fire Event : ");
  Serial.println(fireCount);

  Serial.print("Time Since Start : ");
  Serial.print(millis() / 1000);
  Serial.println(" sec");

  Serial.println("Location : Laboratory");

  Serial.println("+CMGS: 17");
  Serial.println("OK");

  Serial.println("SMS Delivered Successfully");

  Serial.println("-----------------------------------");
  Serial.println();

}
