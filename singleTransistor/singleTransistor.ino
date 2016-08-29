void setup() {
  // put your setup code here, to run once:
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int leftReading = analogRead(A0);
  int leftPower = map(leftReading, 0, 1023, 0, 255);

  analogWrite(5, leftPower);

  int rightReading = analogRead(A1);
  int rightPower = map(rightReading, 0, 1023, 0, 255);

  analogWrite(6, rightPower);

  delay(50);

  
}
