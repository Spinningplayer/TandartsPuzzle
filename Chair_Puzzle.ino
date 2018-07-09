// Inputs
#define iLoop 3
#define iSwitch 4

// Outputs
#define redLed 8
#define sound 7
#define light 6
#define greenLed 5

#define greenLedDisplay 11
#define redLedDisplay 10

#define bolt 12

// Switch states
bool loopHigh = false;
bool switchHigh = false;

int lastTime = 0;
bool blinkState = false;

bool done = false;

void setup() {
  Serial.begin(9600);
  
  Serial.println("[*] Setting pinmodes");
  // Inputs
  pinMode(iLoop, INPUT);
  pinMode(iSwitch, INPUT);

  // Outputs
  pinMode(redLed, OUTPUT);
  pinMode(sound, OUTPUT);
  pinMode(light, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(greenLedDisplay, OUTPUT);
  pinMode(redLedDisplay, OUTPUT);
  pinMode(bolt, OUTPUT);

  Serial.println("[*] Pulling outputs low");
  digitalWrite(redLed, HIGH);
  digitalWrite(sound, LOW);
  digitalWrite(light, HIGH);
  digitalWrite(greenLed, HIGH);
  digitalWrite(greenLedDisplay, HIGH);
  digitalWrite(redLedDisplay, HIGH);
  digitalWrite(bolt, LOW);
  Serial.println("[*] Starting main loop");
}

void loop() {
  Serial.println("Switch: " + String(digitalRead(iSwitch)));
  Serial.println("Loop: " + String(digitalRead(iLoop)));
  if(digitalRead(iSwitch)) {
    Serial.println("On loop");
    if(!digitalRead(iLoop)) {
      if((millis() - lastTime) > 500) {
        Serial.println("Blink");
        if(blinkState) {
          digitalWrite(redLed, HIGH);
          digitalWrite(redLedDisplay, HIGH);
        } else {
          digitalWrite(redLed, LOW);
          digitalWrite(redLedDisplay, LOW);
        }
        blinkState = !blinkState;
        lastTime = millis();
      }  
    } else {
      digitalWrite(redLed, HIGH);
      digitalWrite(redLedDisplay, HIGH);
    }
    

    if(digitalRead(iLoop)) {
      if(!done) {
       Serial.println("Solved loop");
      digitalWrite(redLed, HIGH);
      digitalWrite(redLedDisplay, HIGH);
      delay(1000);
      digitalWrite(greenLed, LOW);
      digitalWrite(greenLedDisplay, LOW);
      digitalWrite(sound, HIGH);
      delay(100);
      digitalWrite(sound, LOW);
      digitalWrite(light, LOW);
      delay(500);
      digitalWrite(light, HIGH);
      delay(500);
      digitalWrite(light, LOW);
      delay(500);
      digitalWrite(light, HIGH);
      delay(500);
      digitalWrite(light, LOW);
      delay(500);
      digitalWrite(light, HIGH);
      delay(500);
      digitalWrite(light, LOW);
      delay(500);
      digitalWrite(light, HIGH);
      delay(500);
      digitalWrite(light, LOW);
      digitalWrite(bolt, HIGH);
      done = true; 
    }
    digitalWrite(greenLed, LOW);
    digitalWrite(greenLedDisplay, LOW);
  } else {
    digitalWrite(greenLed, HIGH);
    digitalWrite(greenLedDisplay, HIGH);
  }
    
  } else {
    digitalWrite(redLed, HIGH);
    digitalWrite(redLedDisplay, HIGH);
    digitalWrite(greenLed, HIGH);
    digitalWrite(greenLedDisplay, HIGH);
    digitalWrite(redLedDisplay, HIGH);
    digitalWrite(light, HIGH);
    digitalWrite(bolt, LOW);
    done = false;
  }

}
