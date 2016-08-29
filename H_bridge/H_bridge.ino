int NPN_left = 3;  // Transistor 3
int PNP_right = 2; // Transistor 2

int NPN_right = 9; // Transistor 4
int PNP_left = 8;  // Transistor 1

byte mode = 0;

void setup() {
 
  pinMode(NPN_left, OUTPUT);  
  pinMode(PNP_right, OUTPUT);  
  
  pinMode(NPN_right, OUTPUT);  
  pinMode(PNP_left, OUTPUT);  
  Serial.begin(9600);
  //Serial.println("Type F (forward), R (reverse), or S (stop)"); 
}


void loop()
{
  int potReading = analogRead(A1);
  int pwm_power = 0;
  
  if(potReading > 600)
  {
    mode = 70;
    pwm_power = map(potReading, 600, 1023, 128, 255);  
  }
  
  else if(potReading > 440)
  {
    mode = 0;
  }

  else
  {
    mode = 82;
    pwm_power = map(potReading, 440, 0, 128, 255); 
  }
  /*
  if(Serial.available() > 0 )
  {
    mode = Serial.read();
    Serial.write(mode);
    Serial.println("");
  } */
  
  // COUNTERCLOCKWISE
  if(mode == 70)
  {
    digitalWrite(PNP_right, HIGH);  //off
    digitalWrite(NPN_left, LOW);  //off
    digitalWrite(PNP_left, LOW);  //on
    analogWrite(NPN_right, pwm_power);  //PWM on
  }

  // CLOCKWISE
  else if(mode == 82)
  {
    digitalWrite(PNP_right, LOW);  //on
    analogWrite(NPN_left, pwm_power);  //PWM on
    digitalWrite(PNP_left, HIGH);  //off
    digitalWrite(NPN_right, LOW);  //off
  }

  // STOP
  else
  {
    digitalWrite(PNP_right, HIGH);  //off
    digitalWrite(NPN_left, LOW);  //off
    digitalWrite(PNP_left, HIGH);  //off
    digitalWrite(NPN_right, LOW);  //off
  }  
}

