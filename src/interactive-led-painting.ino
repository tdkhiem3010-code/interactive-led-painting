
const int LED1 = 5;
const int LED2 = 6;
const int LED3 = 9;

const int TRIG = 10;
const int ECHO = 11;
const int LIGHT_SENSOR = A0;

const int DISTANCE_LIMIT = 30;
const int LIGHT_THRESHOLD = 500;

const unsigned long NEAR_TIME = 3000;

unsigned long nearStart = 0;
bool personDetected = false;

void tatTatCaDen() {
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
}

float doKhoangCach() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG, LOW);

  unsigned long t = pulseIn(ECHO, HIGH, 30000);

  if (t == 0) return 999;

  return t * 0.0343 / 2;
}

void batDen(int den) {
  tatTatCaDen();

  if (den == 1) {
    digitalWrite(LED1, HIGH);
  }
  else if (den == 2) {
    digitalWrite(LED2, HIGH);
  }
  else if (den == 3) {
    digitalWrite(LED3, HIGH);
  }
}

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);

  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  Serial.begin(9600);

  batDen(1);
}

void loop() {
  float khoangCach = doKhoangCach();
  int anhSang = analogRead(LIGHT_SENSOR);

  // Kiem tra vat the co o gan lien tuc 3 giay
  if (khoangCach <= DISTANCE_LIMIT) {

    if (nearStart == 0) {
      nearStart = millis();
    }

    if (millis() - nearStart >= NEAR_TIME) {
      personDetected = true;
    }

  } else {
    nearStart = 0;
    personDetected = false;
  }

  // Uu tien 1: Co nguoi o gan lien tuc 3 giay
  if (personDetected) {
    batDen(3);
  }

  // Uu tien 2: Troi toi
  else if (anhSang > LIGHT_THRESHOLD) {
    batDen(2);
  }

  // Uu tien 3: Trang thai mac dinh
  else {
    batDen(1);
  }

  Serial.print("Khoang cach: ");
  Serial.print(khoangCach);
  Serial.print(" cm | Anh sang: ");
  Serial.print(anhSang);
  Serial.print(" | Nguoi den gan: ");
  Serial.print(personDetected);
  Serial.print(" | Den dang bat: ");

  if (personDetected) {
    Serial.println("DEN 3");
  }
  else if (anhSang > LIGHT_THRESHOLD) {
    Serial.println("DEN 2");
  }
  else {
    Serial.println("DEN 1");
  }

  delay(100);
}
