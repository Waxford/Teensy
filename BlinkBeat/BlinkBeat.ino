
int fixedResistor = 10000;
int thermistorNominal = 10000;
int temperatureNominal = 25;
int bCoefficient = 3950;
int led = 13;
int red = 14;
int yel = 15;
int gre = 16;
int whi = 17;
int blu = 18;
int therm = 21;

int readingNum = 0;

void setup() {                
  pinMode(led, OUTPUT);   
  pinMode(red, OUTPUT);   
  pinMode(yel, OUTPUT);   
  pinMode(gre, OUTPUT);   
  pinMode(whi, OUTPUT);   
  pinMode(blu, OUTPUT);
  pinMode(therm, INPUT);
  Serial.begin(9600);
  analogReference(EXTERNAL);
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
  TakeReading();
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

void TakeReading(){
  float val = 0;
  uint8_t i;
  for(i=0; i < 5; ++i){
    val += analogRead(therm);
    delay(10);
  }
  val /= 5.0;
  Serial.print("avg analog read: ");
  Serial.println(val);

  float teensyCelsius = 25 + (val - 1023) / 11.3;
  Serial.print("Teensy ADC: ");
  Serial.println(teensyCelsius);

  float thermResist;
  thermResist = (1023 / val) - 1;
  thermResist = fixedResistor / thermResist;
  Serial.print("Thermistor resistance: ");
  Serial.println(thermResist);

  float steinhart;
  steinhart = thermResist / thermistorNominal;
  steinhart = log(steinhart);
  steinhart /= bCoefficient;
  steinhart += 1.0 / (temperatureNominal + 273.15);
  steinhart = 1.0 / steinhart;
  steinhart -= 273.15;

  //Serial.print("Temperature: ");
  //Serial.print(steinhart);
  //Serial.println(" degrees C");

  float hacktronicsTemp = log(((10240000/val) - 10000));
  hacktronicsTemp = 1.0 / (0.001129148 + (0.000234125 * hacktronicsTemp) + (0.0000000876741 * hacktronicsTemp * hacktronicsTemp * hacktronicsTemp));
  hacktronicsTemp = hacktronicsTemp - 273.15;
  Serial.print("Temperature reading ");
  Serial.print(readingNum++);
  Serial.print(": ");
  Serial.print(hacktronicsTemp);
  Serial.println(" degrees C");
}

