// EMF Detector for LED Bargraph v1.0
// 5.12.2009
// original code/project by Aaron ALAI - aaronalai1@gmail.com
// modified for use w/ LED bargraph by Collin Cunningham - collin@makezine.com


#define NUMREADINGS 15 // raise this number to increase data smoothing

int senseLimit = 15; // raise this number to decrease sensitivity (up to 1023 max)
int probePin = 5; // analog 5
int val = 0; // reading from probePin

int LED1 = 11;  // connections
int LED2 = 10;  // to
int LED3 = 9;   // LED
int LED4 = 8;   // bargraph
int LED5 = 7;   // anodes
int LED6 = 6;   // with
int LED7 = 5;   // resistors
int LED8 = 4;   // in
int LED9 = 3;   // series
int LED10 = 2;  // 

int buzzer = 13; //buzzer
//int bzzrFreq = average*50;
//int bzzrDur = 100; //buzzer duration

// variables for smoothing

int readings[NUMREADINGS];                // the readings from the analog input
int index = 0;                            // the index of the current reading
int total = 0;                            // the running total
int average = 0;                          // final average of the probe reading


void setup() {

  pinMode(2, OUTPUT);  // specify LED bargraph outputs
  pinMode(3, OUTPUT); 
  pinMode(4, OUTPUT); 
  pinMode(5, OUTPUT); 
  pinMode(6, OUTPUT); 
  pinMode(7, OUTPUT); 
  pinMode(8, OUTPUT); 
  pinMode(9, OUTPUT); 
  pinMode(10, OUTPUT); 
  pinMode(11, OUTPUT); 

  pinMode(buzzer, OUTPUT); //buzzer

  Serial.begin(9600);  // initiate serial connection for debugging/etc

  for (int i = 0; i < NUMREADINGS; i++)
    readings[i] = 0;                      // initialize all the readings to 0
}

void loop() {


  val = analogRead(probePin);  // take a reading from the probe

  if(val >= 1){                // if the reading isn't zero, proceed

    val = constrain(val, 1, senseLimit);  // turn any reading higher than the senseLimit value into the senseLimit value
    val = map(val, 1, senseLimit, 1, 1023);  // remap the constrained value within a 1 to 1023 range

    total -= readings[index];               // subtract the last reading
    readings[index] = val; // read from the sensor
    total += readings[index];               // add the reading to the total
    index = (index + 1);                    // advance to the next index

    if (index >= NUMREADINGS)               // if we're at the end of the array...
      index = 0;                            // ...wrap around to the beginning

    average = total / NUMREADINGS;          // calculate the average


    if (average > 50){                // if the average is over 50 ...
      digitalWrite(LED1, HIGH);   // light the first LED
    }
    else{                         // and if it's not ...
      digitalWrite(LED1, LOW);    // turn that LED off
      noTone(buzzer);
    }

    if (average > 150){               // and so on ...
      digitalWrite(LED2, HIGH);
      tone(buzzer, 50);
    }
    else{
      digitalWrite(LED2, LOW);
      noTone(buzzer);
    }

    if (average > 250){
      digitalWrite(LED3, HIGH);
      tone(buzzer, 500);
    }
    else{
      digitalWrite(LED3, LOW);
      noTone(buzzer);
    }

    if (average > 350){
      digitalWrite(LED4, HIGH);
      tone(buzzer, 1000);
    }
    else{
      digitalWrite(LED4, LOW);
      noTone(buzzer);
    }

    if (average > 450){
      digitalWrite(LED5, HIGH);
      tone(buzzer, 2000);
    }
    else{
      digitalWrite(LED5, LOW);
      noTone(buzzer);
    }

    if (average > 550){
      digitalWrite(LED6, HIGH);
      tone(buzzer, 4000);
    }
    else{
      digitalWrite(LED6, LOW);
      noTone(buzzer);
    }

    if (average > 650){
      digitalWrite(LED7, HIGH);
      tone(buzzer, 8000);
    }
    else{
      digitalWrite(LED7, LOW);
      noTone(buzzer);
    }

    if (average > 750){
      digitalWrite(LED8, HIGH);
      tone(buzzer, 15000);
    }
    else{
      digitalWrite(LED8, LOW);
      noTone(buzzer);
    }

    if (average > 850){
      digitalWrite(LED9, HIGH);
      tone(buzzer, 25000);
    }
    else{
      digitalWrite(LED9, LOW);
      noTone(buzzer);
    }

    if (average > 950){
      digitalWrite(LED10, HIGH);
      tone(buzzer, 50000);
    }
    else{
      digitalWrite(LED10, LOW);
      noTone(buzzer);
    }


    Serial.println(val); // use output to aid in calibrating
  }

}
