#include <NanitLib.h>
#include "pitches.h"

byte buzzPin = P4_2;

int verseNotes[] = {E5, E5, E5, D5, E5, F5, G5, F5, E5, D5, C5, E5, B4, E5, A4, GS4, A4, B4, C5, D5,
                    E5, E5, E5, D5, E5, F5, G5, F5, E5, D5, C5, A4, E5, GS4, A4, A4, 0,
                    B4, B4, E5, D5, C5, B4, A4, B4, C5, A4, B4, B4, C5, C5, D5, D5, E5, E5, 0,
                    B4, B4, E5, D5, C5, B4, A4, B4, C5, A4, B4, B4, C5, E5, B4, E5, A4, B4, C5, D5, E5, F5};

int chorusNotes[] = {G5,  FS5, G5, E5, D5, D5,  G5, F5, E5, D5, C5, C5, D5, D5, E5, D5, C5, D5, E5, F5,
                    G5, FS5, G5, E5, D5, D5, G5, F5, E5, D5, C5, A4, E5, GS4, A4, A4, 0};

int verseDelays[] = {1125, 375, 375, 375, 375, 375, 1125, 375, 750, 750, 750, 750, 750, 750, 375, 375, 375, 375, 750, 750,
                    1125, 375, 375, 375, 375, 375, 1125, 375, 750, 750, 750, 750, 1125, 375, 1500, 750, 750,
                    1125, 375, 375, 375, 375, 375, 375, 375, 375, 375, 750, 750, 1125, 375, 750, 750, 1500, 750, 750,
                    1125, 375, 375, 375, 375, 375, 375, 375, 375, 375, 750, 750, 750, 750, 750, 750, 375, 375, 375, 375, 750, 750};

int chorusDelays[] = {1125, 375, 750, 750, 750, 750, 375, 375, 375, 375, 750, 750, 750, 750, 1125, 375, 375, 375, 375, 375,
                      1125, 375, 750, 750, 750, 750, 375, 375, 375, 375, 750, 750, 1125, 375, 1500, 750, 750};

int verseDurations[] = {1075, 325, 375, 375, 325, 325, 1075, 325, 700, 700, 700, 700, 700, 700, 375, 375, 375, 375, 700, 700,
                    1075, 325, 375, 375, 325, 325, 1075, 325, 700, 700, 700, 700, 1075, 325, 1450, 750, 750,
                    1075, 325, 375, 355, 325, 325, 375, 375, 325, 325, 700, 700, 1075, 325, 700, 700, 1450, 750, 750,
                    1075, 325, 375, 375, 325, 325, 375, 375, 325, 325, 700, 700, 700, 700, 700, 700, 375, 375, 375, 375, 700, 700};

int chorusDurations[] = {1075, 325, 700, 700, 700, 700, 375, 375, 325, 325, 700, 700, 700, 700, 1125, 325, 375, 375, 325, 325,
                      1075, 325, 700, 700, 700, 700, 375, 375, 325, 325, 700, 700, 1075, 325, 1450, 750, 750};

byte verseSize = sizeof(verseNotes)/sizeof(verseNotes[0]);
byte chorusSize = sizeof(chorusNotes)/sizeof(chorusNotes[0]);

void setup() {
  Nanit_Base_Start();
  pinMode(buzzPin, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  play(verseNotes, verseDurations, verseDelays, verseSize);
  play(chorusNotes, chorusDurations, chorusDelays, chorusSize);
  play(chorusNotes, chorusDurations, chorusDelays, chorusSize);
  noTone(buzzPin);
  delay(2000);
}

void play(int notes[], int durations[], int delays[], byte size) {
  for(byte i = 0; i < size; i++){
    tone(buzzPin, notes[i], durations[i]);
    delay(delays[i]);
  }
}
