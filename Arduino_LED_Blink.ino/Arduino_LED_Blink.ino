int led = 13;
int buttonPin = 2;
int buttonState = 0;

void setup(){
  pinMode(led, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop(){
  buttonState = digitalRead(buttonPin);

  if(buttonState == HIGH){
    digitalWrite(led, HIGH);
//    delay (3000);
  } else {
    digitalWrite(led, LOW);
//    delay(10);
  }
}

