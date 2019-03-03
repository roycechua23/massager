int motorA1 = 3;
int motorA2 = 4;
int motorB1 = 5;
int motorB2 = 6;
int motorC1 = 9;
int motorC2 = 8;
int motorD1 = 11;
int motorD2 = 10;

int button = 2;
int buttonState = 0;
int counter = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);
  pinMode(motorC1, OUTPUT);
  pinMode(motorC2, OUTPUT);
  pinMode(motorD1, OUTPUT);
  pinMode(motorD2, OUTPUT);
  pinMode(button, INPUT);
  mode0();
}

void mode0(){
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, LOW);
  digitalWrite(motorC1, LOW);
  digitalWrite(motorC2, LOW);
  digitalWrite(motorD1, LOW);
  digitalWrite(motorD2, LOW);
}

void mode1(){
  analogWrite(motorA1, 150);
  analogWrite(motorB1, 150);
  analogWrite(motorC1, 150);
  analogWrite(motorD1, 150);
  delay(1000);
  digitalWrite(motorA2, 0);
  digitalWrite(motorB2, 0);
  digitalWrite(motorC2, 0);
  digitalWrite(motorD2, 0);
  delay(1000);
}

void mode2(){
  analogWrite(motorA1, 180);
  analogWrite(motorB1, 180);
  analogWrite(motorC1, 180);
  analogWrite(motorD1, 180);
  delay(1000);
  digitalWrite(motorA2, 0);
  digitalWrite(motorB2, 0);
  digitalWrite(motorC2, 0);
  digitalWrite(motorD2, 0);
  delay(1000);
}

void loop() {
  if(counter == 0){
    mode0();
  }
  buttonState = digitalRead(button);
  if(buttonState == 1){
    counter++;
    if(counter == 1){
      mode1();
      delay(150);
    }
    else if(counter == 2){
      mode2();
      delay(150);
      
    }else if(counter >= 3){
      mode0();
      counter = 0;
      delay(500);
    }
  }else{
  
  }
   
}
