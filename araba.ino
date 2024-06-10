#define echoPin 12 
#define trigPin 13 

#define MotorR1 7 
#define MotorR2 6 
#define MotorRenable 9 
#define MotorL1 5 
#define MotorL2 4 
#define MotorLenable 3 

#define MESAFE_SINIRI 5 

long sure, uzaklik;

void setup() {
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);

  pinMode(MotorL1, OUTPUT);
  pinMode(MotorL2, OUTPUT);
  pinMode(MotorLenable, OUTPUT); 
  pinMode(MotorR1, OUTPUT);
  pinMode(MotorR2, OUTPUT);
  pinMode(MotorRenable, OUTPUT);

  Serial.begin(9600); 
}

void loop() {
  uzaklik = mesafeOlc();

  Serial.println(uzaklik);

  if (uzaklik < MESAFE_SINIRI) { 
    delay(500);
    sag();
    delay(500);
    sol();
    delay(500);
  } else { 
    ileri(); 
  }
}

long mesafeOlc() {
  long toplamUzaklik = 0;
  const int olcumSayisi = 5;

  for (int i = 0; i < olcumSayisi; i++) {
    digitalWrite(trigPin, LOW); 
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH); 
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW); 

    sure = pulseIn(echoPin, HIGH); 
    toplamUzaklik += sure / 29.1 / 2; 
    delay(10);
  }

  return toplamUzaklik / olcumSayisi; 
}

void ileri() { 
  digitalWrite(MotorR1, HIGH); 
  digitalWrite(MotorR2, LOW); 
  analogWrite(MotorRenable, 90); 

  digitalWrite(MotorL1, HIGH); 
  digitalWrite(MotorL2, LOW); 
  analogWrite(MotorLenable, 90); 
}

void sag() { 
  digitalWrite(MotorR1, LOW); 
  digitalWrite(MotorR2, HIGH); 
  analogWrite(MotorRenable, 90); 

  digitalWrite(MotorL1, HIGH); 
  digitalWrite(MotorL2, LOW); 
  analogWrite(MotorLenable, 90); 
}

void sol() { 
  digitalWrite(MotorR1, HIGH); 
  digitalWrite(MotorR2, LOW); 
  analogWrite(MotorRenable, 90); 

  digitalWrite(MotorL1, LOW); 
  digitalWrite(MotorL2, HIGH); 
  analogWrite(MotorLenable, 90); 
}

void geri() { 
  digitalWrite(MotorR1, LOW); 
  digitalWrite(MotorR2, HIGH); 
  analogWrite(MotorRenable, 90); 

  digitalWrite(MotorL1, LOW); 
  digitalWrite(MotorL2, HIGH); 
  analogWrite(MotorLenable, 90); 
}


