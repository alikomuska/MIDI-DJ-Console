#include "MIDIUSB.h"
#define NUM_POTS 9
#define NUM_ROTS 2
#define NUM_BUTS 2

const int CHANNEL = 0;
const int NOISE_THRESHOLD = 2;
//int ccNumbers[] = {0, 1, 2, 3, 4, 5, 6, 7}; //not needed maybe later


//#########  POTENSIOMETERS ############
int potPin[] = {A0, A1, A2, A3, A6, A7, A8, A10, A9};  // Potentiometer pins
int lastValues[] = {-1, -1, -1, -1, -1, -1, -1, -1, -1};  // To prevent sending redundant MIDI messages


//#########  ROTARY ############
int rotPin[] = {7, 5, 14, 16};
int rotaryLastStates[NUM_ROTS];


//########## BUTTONS ############
int butPin[] = {3,15};
bool lastButtonState[NUM_BUTS] = {HIGH, HIGH};


//##########   MIDI  ############
int loopValue = 0;
bool loopOn[NUM_BUTS] = {false, false};



// Send a MIDI Control Change message
void controlChange(byte channel, byte control, byte value) {
  midiEventPacket_t event = {0x0B, 0xB0 | channel, control, value};
  MidiUSB.sendMIDI(event);
}

void _initPot() {
  // Could put some more thought into it, but works fine
  int midiValue, potValue;
  double start = millis();
  for(int i=0; i<NUM_POTS; i++){
    pinMode(potPin[i], INPUT);
  }
  while (true) {
    midiEventPacket_t rx = MidiUSB.read(); 

    // Check if we got any MIDI packet from the computer
    if (rx.header != 0) { //use Monitor State midi out from traktor
      break; // exit the loop
    }

    delay(5); // small pause so we don't hammer USB bus
    if (millis() - start > 4000) {
      break;
    }
  }

  for(int i=0; i<NUM_POTS; i++){
    potValue = constrain(analogRead(potPin[i]), 0, 1023);
    midiValue = map(potValue, 0, 1023, 0, 127); // Convert to MIDI range (0–127)
    controlChange(CHANNEL, i, midiValue);  // Channel 0, CC #7 = volume (standard)
    lastValues[i] = midiValue;
  }
  MidiUSB.flush(); 
}

void _initRot(){
  for(int i=0; i<(NUM_ROTS*2); i++){
     pinMode(rotPin[i], INPUT_PULLUP);
  }
  for(int i=0; i<NUM_ROTS; i++){
    rotaryLastStates[i] = digitalRead(rotPin[i*2]);
  }
  
}

void _iniBut(){
  for(int i=0; i<NUM_BUTS; i++){
    pinMode(butPin[i], INPUT_PULLUP);
  }
}

void initConsole(){
  _initPot();
  _initRot();
  _iniBut();
  }

//Potentiometer update
void update_pot(){
  int midiValue, potValue;
  for(int i=0; i<NUM_POTS; i++){
    potValue = analogRead(potPin[i]);
    midiValue = map(potValue, 0, 1023, 0, 127);
    if(abs(midiValue - lastValues[i]) > NOISE_THRESHOLD){ //if you add capasitors so the analogReads are noice resistant you can check if the value changed
      controlChange(CHANNEL, i, midiValue);
      lastValues[i] = midiValue;
      Serial.println(i);
      Serial.println(potValue);
    }
  }
}

  //0 -> 1/32
  //7 -> 1/16
  //20 -> 1/8
  //32 -> 1/4
  //45 -> 1/2
  //58 -> 1
  //70 -> 2
  //83 -> 4
  //96 -> 8
  //108 -> 16
  //121 -> 32
void update_rot(){
  int rotState;
  int pinA, pinB;
  for (int i = 0; i < NUM_ROTS; i++) {
    pinA = rotPin[2*i];
    pinB = rotPin[2*i+1];
    rotState = digitalRead(pinA);
    if(rotState != rotaryLastStates[i]){
      if (rotState == HIGH) {
        if(digitalRead(pinB) == rotState) {
          //loopValue = min(loopValue + 13, 127);
          controlChange(CHANNEL, NUM_POTS+i*2, 127);
          Serial.print(i);
          Serial.println(" LOW");
        } else {
          //loopValue = max(loopValue - 13, 0);
          controlChange(CHANNEL, NUM_POTS+i*2+1, 127);
          Serial.print(i);
          Serial.println(" HIGH");
        }
      }
      rotaryLastStates[i] = rotState;
    }
  }
}


//Buttons
void update_buts(){
  bool currentState;

  for(int i=0; i<NUM_BUTS; i++){
    // button pressed (HIGH → LOW)
    currentState = digitalRead(butPin[i]);
    if (currentState == LOW && lastButtonState[i] == HIGH) {
      controlChange(CHANNEL, NUM_POTS + NUM_ROTS*2 + i, 127);
      Serial.print(NUM_POTS + NUM_ROTS*2 + i);
      Serial.println(" LOOP");  
    }
    lastButtonState[i] = currentState;
    //loopOn[i]= !loopOn[i];
 

    // button released (LOW → HIGH)
    if (currentState == HIGH && lastButtonState[i] == LOW) {
      controlChange(CHANNEL, NUM_POTS + NUM_ROTS*2 + i*2, 127);
      Serial.println("Realise");
      lastButtonState[i] = currentState;
    }
  }  
}


void setup() {
  Serial.begin(115200);
  initConsole();
}



void loop() {
  //Potentiometers
  update_pot();
  
  //Rotary Encoders
  update_rot();

  //Buttons
  update_buts();

  MidiUSB.flush();
  delay(1);
}
