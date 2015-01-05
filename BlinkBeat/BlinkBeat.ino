
int led = 13;
int red = 14;
int yel = 15;
int gre = 16;
int whi = 17;
int blu = 18;

void setup() {                
  pinMode(led, OUTPUT);   
  pinMode(red, OUTPUT);   
  pinMode(yel, OUTPUT);   
  pinMode(gre, OUTPUT);   
  pinMode(whi, OUTPUT);   
  pinMode(blu, OUTPUT);
}

void loop() {
  digitalWrite(red, HIGH);
  delay(200);
  digitalWrite(yel, HIGH);
  delay(200);
  digitalWrite(gre, HIGH);
  delay(200);
  digitalWrite(whi, HIGH);
  delay(50);
  digitalWrite(whi, LOW);
  delay(100);
  digitalWrite(whi, HIGH);
  delay(50);
  digitalWrite(whi, LOW);
  delay(100);
  digitalWrite(whi, HIGH);
  delay(50);
  digitalWrite(whi, LOW);
  delay(100);
  digitalWrite(whi, HIGH);
  delay(50);
  digitalWrite(whi, LOW);
  delay(50);
  digitalWrite(whi, HIGH);
  delay(50);
  digitalWrite(whi, LOW);
  delay(50);
  digitalWrite(whi, HIGH);
  delay(50);
  digitalWrite(whi, LOW);
  digitalWrite(red, LOW);
  digitalWrite(yel, LOW);
  digitalWrite(gre, LOW);
  delay(50);
  digitalWrite(blu, HIGH);
  delay(1000);
  digitalWrite(blu, LOW);
  delay(100);
  digitalWrite(blu, HIGH);
  delay(50);
  digitalWrite(blu, LOW);
  delay(100);
  digitalWrite(blu, HIGH);
  delay(50);
  digitalWrite(blu, LOW);
  delay(100);
  digitalWrite(blu, HIGH);
  delay(50);
  digitalWrite(blu, LOW);
}
