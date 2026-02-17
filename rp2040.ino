#include <Adafruit_TinyUSB.h>

Adafruit_USBD_MIDI usb_midi;

// Send Note On
void midiNoteOn(uint8_t channel, uint8_t note, uint8_t velocity) {
  usb_midi.write((uint8_t)(0x90 | ((channel - 1) & 0x0F)));
  usb_midi.write(note);
  usb_midi.write(velocity);
}

// Send Note Off
void midiNoteOff(uint8_t channel, uint8_t note, uint8_t velocity) {
  usb_midi.write((uint8_t)(0x80 | ((channel - 1) & 0x0F)));
  usb_midi.write(note);
  usb_midi.write(velocity);
}

void setup() {
  usb_midi.begin();
}

void loop() {
  midiNoteOn(1, 60, 100);  // Channel 1, Middle C
  delay(100);

  midiNoteOff(1, 60, 0);
  delay(900); // total 1 second cycle
}
