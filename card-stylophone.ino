/*
 * Arduino Music Playing Program
 * This project uses basic pitch functions to play musical notes
 * Different playing modes can be selected by changing the function in the main
 * loop Uses the tone function to generate sounds and pitches.h library to
 * define note frequencies Includes readCapacitivePin function to measure
 * capacitance on pins
 */

#include "pitches.h"  // Include header file containing note frequency definitions

// Basic configuration parameters
int notelength = 20;  // Define note duration (milliseconds)
int outputpin = 9;    // Define sound output pin
int capacitance = 8;  // Define capacitance detection threshold

// Canon 
int canonMelody[] = {
    NOTE_D4, NOTE_A3, NOTE_B3, NOTE_FS3, NOTE_G3, NOTE_D3, NOTE_G3, NOTE_A3
};
int canonNoteDurations[] = {
    4, 4, 4, 4, 4, 4, 4, 4
};  // quarter note

// Initialization setup
void setup(void) {
  // Initialize Arduino board and emit a beep to indicate normal operation
  tone(outputpin, NOTE_A4, 500);  // Play note A4 for 500 milliseconds
}

// Capacitive touch detection function
#include "pins_arduino.h"  // Include Arduino pin definitions

uint8_t readCapacitivePin(int pinToMeasure) {
  // Declare pointers to port registers
  volatile uint8_t* port;
  volatile uint8_t* ddr;
  volatile uint8_t* pin;
  byte bitmask;

  // Get port register addresses for specified pin
  port = portOutputRegister(digitalPinToPort(pinToMeasure));
  ddr = portModeRegister(digitalPinToPort(pinToMeasure));
  bitmask = digitalPinToBitMask(pinToMeasure);
  pin = portInputRegister(digitalPinToPort(pinToMeasure));

  // Set pin states
  *port &= ~(bitmask);  // Clear output port bit
  *ddr |= bitmask;      // Set data direction to output
  delay(1);             // Brief delay

  noInterrupts();      // Disable interrupts for precise timing
  *ddr &= ~(bitmask);  // Set data direction to input
  *port |= bitmask;    // Enable pull-up resistor

  // Measure capacitor charging time
  uint8_t cycles = 17;  // Maximum cycle count
  // Check pin state to determine capacitor charging cycles
  if (*pin & bitmask) {
    cycles = 0;
  } else if (*pin & bitmask) {
    cycles = 1;
  }
  // ... Repeat checks up to 16 cycles
  else if (*pin & bitmask) {
    cycles = 16;
  }

  interrupts();  // Re-enable interrupts

  // Reset pin states
  *port &= ~(bitmask);  // Clear output
  *ddr |= bitmask;      // Set to output mode

  return cycles;  // Return charging cycle count
}

// Main loop function
void loop(void) {
  customPlay();  // play Custom Music
}

// Aeolian scale (natural minor) capacitive touch detection function
void aeoliancap(void) {
  // Check capacitance on each pin, play corresponding note when above threshold
  if (readCapacitivePin(6) > capacitance) {
    tone(outputpin, NOTE_A4, notelength);
  }  // Note A4
  if (readCapacitivePin(5) > capacitance) {
    tone(outputpin, NOTE_B4, notelength);
  }  // Note B4
  if (readCapacitivePin(4) > capacitance) {
    tone(outputpin, NOTE_C5, notelength);
  }  // Note C5
  if (readCapacitivePin(3) > capacitance) {
    tone(outputpin, NOTE_D5, notelength);
  }  // Note D5
  if (readCapacitivePin(2) > capacitance) {
    tone(outputpin, NOTE_E5, notelength);
  }  // Note E5
  if (readCapacitivePin(7) > capacitance) {
    tone(outputpin, NOTE_F5, notelength);
  }  // Note F5
  if (readCapacitivePin(8) > capacitance) {
    tone(outputpin, NOTE_G5, notelength);
  }  // Note G5
  if (readCapacitivePin(10) > capacitance) {
    tone(outputpin, NOTE_A5, notelength);
  }  // Note A5
  if (readCapacitivePin(11) > capacitance) {
    tone(outputpin, NOTE_B5, notelength);
  }  // Note B5
  if (readCapacitivePin(12) > capacitance) {
    tone(outputpin, NOTE_C6, notelength);
  }  // Note C6
}

// Aeolian bass and treble combination capacitive touch detection function
void aeolianbt(void) {
  // Check pins and play combinations of bass and treble notes
  if (readCapacitivePin(6) > capacitance) {
    tone(outputpin, NOTE_A1, notelength);
  }  // Bass A1
  if (readCapacitivePin(5) > capacitance) {
    tone(outputpin, NOTE_C2, notelength);
  }  // Bass C2
  if (readCapacitivePin(4) > capacitance) {
    tone(outputpin, NOTE_E2, notelength);
  }  // Bass E2
  if (readCapacitivePin(3) > capacitance) {
    tone(outputpin, NOTE_G2, notelength);
  }  // Bass G2
  if (readCapacitivePin(2) > capacitance) {
    tone(outputpin, NOTE_A2, notelength);
  }  // Bass A2
  if (readCapacitivePin(7) > capacitance) {
    tone(outputpin, NOTE_A4, notelength);
  }  // Treble A4
  if (readCapacitivePin(8) > capacitance) {
    tone(outputpin, NOTE_C5, notelength);
  }  // Treble C5
  if (readCapacitivePin(10) > capacitance) {
    tone(outputpin, NOTE_E5, notelength);
  }  // Treble E5
  if (readCapacitivePin(11) > capacitance) {
    tone(outputpin, NOTE_G5, notelength);
  }  // Treble G5
  if (readCapacitivePin(12) > capacitance) {
    tone(outputpin, NOTE_A5, notelength);
  }  // Treble A5
}

// Pentatonic scale mode function
void pentatonic(void) {
  // Trigger different scales based on touch inputs
  if (readCapacitivePin(6) > capacitance) {
    amscale();
  }  // A minor scale
  if (readCapacitivePin(5) > capacitance) {
    dmscale();
  }  // D minor scale
  if (readCapacitivePin(4) > capacitance) {
    e7scale();
  }  // E7 scale
  if (readCapacitivePin(3) > capacitance) {
    fscale();
  }  // F major scale
  if (readCapacitivePin(2) > capacitance) {
    gscale();
  }  // G major scale
}

// A minor scale function
void amscale(void) {
  // Play notes of the A minor scale
  if (readCapacitivePin(7) > capacitance) {
    tone(outputpin, NOTE_A4, notelength);
  }  // Note A4
  if (readCapacitivePin(8) > capacitance) {
    tone(outputpin, NOTE_C5, notelength);
  }  // Note C5
  if (readCapacitivePin(10) > capacitance) {
    tone(outputpin, NOTE_E5, notelength);
  }  // Note E5
  if (readCapacitivePin(11) > capacitance) {
    tone(outputpin, NOTE_G5, notelength);
  }  // Note G5
  if (readCapacitivePin(12) > capacitance) {
    tone(outputpin, NOTE_A5, notelength);
  }  // Note A5
}

// D minor scale function
void dmscale(void) {
  // Play notes of the D minor scale
  if (readCapacitivePin(7) > capacitance) {
    tone(outputpin, NOTE_D5, notelength);
  }  // Note D5
  if (readCapacitivePin(8) > capacitance) {
    tone(outputpin, NOTE_F5, notelength);
  }  // Note F5
  if (readCapacitivePin(10) > capacitance) {
    tone(outputpin, NOTE_A5, notelength);
  }  // Note A5
  if (readCapacitivePin(11) > capacitance) {
    tone(outputpin, NOTE_C6, notelength);
  }  // Note C6
  if (readCapacitivePin(12) > capacitance) {
    tone(outputpin, NOTE_D6, notelength);
  }  // Note D6
}

// E7 scale function
void e7scale(void) {
  // Play notes of the E7 scale
  if (readCapacitivePin(7) > capacitance) {
    tone(outputpin, NOTE_E5, notelength);
  }  // Note E5
  if (readCapacitivePin(8) > capacitance) {
    tone(outputpin, NOTE_GS5, notelength);
  }  // Note G#5
  if (readCapacitivePin(10) > capacitance) {
    tone(outputpin, NOTE_B5, notelength);
  }  // Note B5
  if (readCapacitivePin(11) > capacitance) {
    tone(outputpin, NOTE_D6, notelength);
  }  // Note D6
  if (readCapacitivePin(12) > capacitance) {
    tone(outputpin, NOTE_E6, notelength);
  }  // Note E6
}

// C major scale function
void cscale(void) {
  // Play notes of the C major scale
  // Repeat C5 note four times
  if (readCapacitivePin(7) > capacitance) {
    tone(outputpin, NOTE_C5, notelength);
    tone(outputpin, NOTE_C5, notelength);
    tone(outputpin, NOTE_C5, notelength);
    tone(outputpin, NOTE_C5, notelength);
  }
  if (readCapacitivePin(8) > capacitance) {
    tone(outputpin, NOTE_E5, notelength);
  }  // Note E5
  if (readCapacitivePin(10) > capacitance) {
    tone(outputpin, NOTE_G5, notelength);
  }  // Note G5
  if (readCapacitivePin(11) > capacitance) {
    tone(outputpin, NOTE_B5, notelength);
  }  // Note B5
  if (readCapacitivePin(12) > capacitance) {
    tone(outputpin, NOTE_C6, notelength);
  }  // Note C6
}

// F major scale function
void fscale(void) {
  // Play notes of the F major scale
  if (readCapacitivePin(7) > capacitance) {
    tone(outputpin, NOTE_F5, notelength);
  }  // Note F5
  if (readCapacitivePin(8) > capacitance) {
    tone(outputpin, NOTE_A5, notelength);
  }  // Note A5
  if (readCapacitivePin(10) > capacitance) {
    tone(outputpin, NOTE_C6, notelength);
  }  // Note C6
  if (readCapacitivePin(11) > capacitance) {
    tone(outputpin, NOTE_E6, notelength);
  }  // Note E6
  if (readCapacitivePin(12) > capacitance) {
    tone(outputpin, NOTE_F6, notelength);
  }  // Note F6
}

// G major scale function
void gscale(void) {
  // Play notes of the G major scale
  if (readCapacitivePin(7) > capacitance) {
    tone(outputpin, NOTE_G5, notelength);
  }  // Note G5
  if (readCapacitivePin(8) > capacitance) {
    tone(outputpin, NOTE_B5, notelength);
  }  // Note B5
  if (readCapacitivePin(10) > capacitance) {
    tone(outputpin, NOTE_D6, notelength);
  }  // Note D6
  if (readCapacitivePin(11) > capacitance) {
    tone(outputpin, NOTE_F6, notelength);
  }  // Note F6
  if (readCapacitivePin(12) > capacitance) {
    tone(outputpin, NOTE_G6, notelength);
  }  // Note G6
}

// Custom play
void customPlay(void) {
  // Play Canon
  if (readCapacitivePin(6) > capacitance) {
    playCanon();
  } 
}

// PlayCanno
void playCanon() {
  for (int thisNote = 0; thisNote < 8; thisNote++) {
    int noteDuration = 1000 / canonNoteDurations[thisNote];
    tone(outputpin, canonMelody[thisNote], noteDuration);

    int pauseBetweenNotes = noteDuration * 1.3;  // 设置音符间的暂停
    delay(pauseBetweenNotes);

    noTone(outputpin);  // 停止音调
  }
}