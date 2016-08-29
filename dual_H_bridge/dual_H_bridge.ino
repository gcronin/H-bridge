
//LEFT SIDE MOTOR
int NPN_left = 3;  //C
int PNP_right = 2; //B

int NPN_right = 9; //D
int PNP_left = 8;  //A

//RIGHT SIDE MOTOR
int NPNleft = 5;  //G
int PNPright = 4; //F

int NPNright = 11;  //H
int PNPleft = 10;  //E


void setup() {
 
  pinMode(NPN_left, OUTPUT);  
  pinMode(PNP_right, OUTPUT);  
  
  pinMode(NPN_right, OUTPUT);  
  pinMode(PNP_left, OUTPUT);  

  pinMode(NPNleft, OUTPUT);  
  pinMode(PNPright, OUTPUT);  

  pinMode(NPNright, OUTPUT);  
  pinMode(PNPleft, OUTPUT);  
  Serial.begin(9600);
}


void loop()
{
  ////////////////////////////LEFT MOTOR///////////////////////////////////////
  int potReadingLeft = analogRead(A1);
  int pwm_power_left = 0;

  if(potReadingLeft > 600)  //COUNTERCLOCKWISE
  {
    pwm_power_left = map(potReadingLeft, 600, 1023, 128, 255);
    digitalWrite(PNP_right, HIGH);  //off
    digitalWrite(NPN_left, LOW);  //off
    digitalWrite(PNP_left, LOW);  //on
    analogWrite(NPN_right, pwm_power_left);  //PWM on  
  }
  
  else if(potReadingLeft > 440)  // STOP
  {
    digitalWrite(PNP_right, HIGH);  //off
    digitalWrite(NPN_left, LOW);  //off
    digitalWrite(PNP_left, HIGH);  //off
    digitalWrite(NPN_right, LOW);  //off
  }

  else  //CLOCKWISE
  {
    pwm_power_left = map(potReadingLeft, 440, 0, 128, 255); 
    digitalWrite(PNP_right, LOW);  //on
    analogWrite(NPN_left, pwm_power_left);  //PWM on
    digitalWrite(PNP_left, HIGH);  //off
    digitalWrite(NPN_right, LOW);  //off
  }


  /////////////////////////////////////RIGHT MOTOR////////////////////////////////////////
  int potReadingRight = analogRead(A0);
  int pwm_power_right = 0;

  if(potReadingRight > 600)  //COUNTERCLOCKWISE
  {
    pwm_power_right = map(potReadingRight, 600, 1023, 128, 255);
    digitalWrite(PNPright, HIGH);  //off
    digitalWrite(NPNleft, LOW);  //off
    digitalWrite(PNPleft, LOW);  //on
    analogWrite(NPNright, pwm_power_right);  //PWM on  
  }
  
  else if(potReadingRight > 440)  // STOP
  {
    digitalWrite(PNPright, HIGH);  //off
    digitalWrite(NPNleft, LOW);  //off
    digitalWrite(PNPleft, HIGH);  //off
    digitalWrite(NPNright, LOW);  //off
  }

  else  //CLOCKWISE
  {
    pwm_power_right = map(potReadingRight, 440, 0, 128, 255); 
    digitalWrite(PNPright, LOW);  //on
    analogWrite(NPNleft, pwm_power_right);  //PWM on
    digitalWrite(PNPleft, HIGH);  //off
    digitalWrite(NPNright, LOW);  //off
  }

}

