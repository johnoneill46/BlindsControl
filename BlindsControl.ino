/*
 * Arduino program that will move servo depending on button pressed
 */
 
int ledPin = 12;                // LED is connected to pin 12
int switchPin = 2;              // switch is connected to pin 2
int val = digitalRead(switchPin);   // read input value and store it in val / variable for reading the pin status


void setup() {
  
  pinMode(ledPin, OUTPUT);      // Set the LED pin as output
  pinMode(switchPin, INPUT);    // Set the switch pin as input
  Serial.begin(9600);
  Serial.println("Application Starting...");
}

void loop(){
 // val = digitalRead(switchPin);   // read input value and store it in val
  
  if (val == LOW) {   
    // check if the button is pressed
    digitalWrite(ledPin, HIGH);   // turn LED on
    //delay(50);
    //digitalWrite(ledPin, LOW);
   // delay(50);
  // Serial.println(digitalRead(switchPin));
  }
  
  if (val == HIGH) {              // check if the button is not pressed
    digitalWrite(ledPin, LOW);    // turn LED off
   // Serial.println(digitalRead(switchPin));
  }
}
