/*
  Morse Code Transmitter
  Michael D'Argenio
  mjdargenio@gmail.com
  https://dargenio.dev
  https://github.com/mjdargen
  September 19, 2019

  Takes input from the serial port and converts it
  to Morse Code. Blinks an LED and buzzes an active
  buzzer to signal the Morse Code.
  
  LED: visual morse code representation
  * Digital output pin 2
  * Has 220 ohm series resistor
  * Lights up every time there is a dot or dash
  
  Active Buzzer: auditory morse code representation 
  * Digital output pin 3
  * Has 100 ohm series resistor to limit volume
  * Beeps every time there is a dot or dash
  
  International Morse Code
  * 1. The length of a dot is one unit.
  * 2. A dash is three units.
  * 3. The space between parts of the same letter is one unit.
  * 4. The space between letters is three units.
  * 5. The space between words is seven units.

  Category        Character                   Code
  Letters         A, a                        · −
  Letters         B, b                        − · · ·
  Letters         C, c                        − · − · 
  Letters         D, d                        − · · 
  Letters         E, e                        · 
  Letters         F, f                        · · − · 
  Letters         G, g                        − − · 
  Letters         H, h                        · · · · 
  Letters         I, i                        · · 
  Letters         J, j                        · − − − 
  Letters         K, k                        − · − 
  Letters         L, l                        · − · · 
  Letters         M, m                        − − 
  Letters         N, n                        − · 
  Letters         O, o                        − − − 
  Letters         P, p                        · − − · 
  Letters         Q, q                        − − · − 
  Letters         R, r                        · − · 
  Letters         S, s                        · · · 
  Letters         T, t                        − 
  Letters         U, u                        · · − 
  Letters         V, v                        · · · − 
  Letters         W, w                        · − − 
  Letters         X, x                        − · · − 
  Letters         Y, y                        − · − − 
  Letters         Z, z                        − − · · 
  Numbers         0                           − − − − − 
  Numbers         1                           · − − − − 
  Numbers         2                           · · − − − 
  Numbers         3                           · · · − − 
  Numbers         4                           · · · · − 
  Numbers         5                           · · · · · 
  Numbers         6                           − · · · · 
  Numbers         7                           − − · · · 
  Numbers         8                           − − − · · 
  Numbers         9                           − − − − · 
  Punctuation     Period [.]                  · − · − · − 
  Punctuation     Comma [,]                   − − · · − − 
  Punctuation     Question Mark [?]           · · − − · · 
  Punctuation     Apostrophe [']              · − − − − · 
  Punctuation     Exclamation Point [!]       − · − · − − 
  Punctuation     Slash/Fraction Bar [/]      − · · − · 
  Punctuation     Parenthesis (Open)          − · − − · 
  Punctuation     Parenthesis (Close)         − · − − · − 
  Punctuation     Ampersand [&]               · − · · · 
  Punctuation     Colon [:]                   − − − · · · 
  Punctuation     Semicolon [;]               − · − · − · 
  Punctuation     Double Dash [=]             − · · · − 
  Punctuation     Plus sign [+]               · − · − · 
  Punctuation     Hyphen, Minus Sign [-]      − · · · · − 
  Punctuation     Underscore [_]              · · − − · − 
  Punctuation     Quotation mark ["]          · − · · − · 
  Punctuation     Dollar sign [$]             · · · − · · − 
  Punctuation     At Sign [@]                 · − − · − ·  

*/

#include <stdio.h>

#define TIME_UNIT 200
#define LED_PIN 2
#define BUZZER_PIN 3

String message = "";

/* set up function */
void setup() {
  // put your setup code here, to run once:

  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  // configure output pins
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  // send an intro:
  Serial.println("Morse code transmitter is ready");
  Serial.println();
}

/* main while loop function */
void loop() {
  // put your main code here, to run repeatedly:

  // are there any bytes available on serial port?
  if (Serial.available() > 0) {
    // read all data into string
    message = Serial.readString();

    // switch to lower case so you don't have to handle every case
    message.toLowerCase();

    morse_transmitter(message);

    Serial.println();
    Serial.println("Ready for next message");
  }

}

/* main transmitter function */
void morse_transmitter(String message) {
  int message_length = message.length();

  for (int i=0; i < message_length; i++) {
    morse_translator(message.charAt(i));
  }
  
}

/* translates character into dots and dashes */
void morse_translator (char letter) {

  switch (letter) {
    // A, a  ->  · −
    case 'a': 
      dot();
      dash();
      letter_pause();
      break;
    // B, b  ->  − · ··
    case 'b':
      dash();
      dot();
      dot();
      dot();
      letter_pause();
      break;
    // C, c  ->  − · − · 
    case 'c':
      dash();
      dot();
      dash();
      dot();
      letter_pause();
      break;
    // D, d  ->  − · · 
    case 'd':
      dash();
      dot();
      dot();
      letter_pause();
      break;
    // E, e  ->  · 
    case 'e':
      dot();
      letter_pause();
      break;
    // F, f  ->  · · − · 
    case 'f':
      dot();
      dot();
      dash();
      dot();
      letter_pause();
      break;
    // G, g  ->  − − · 
    case 'g':
      dash();
      dash();
      dot();
      letter_pause();
      break;
    // H, h  ->  · · · · 
    case 'h':
      dot();
      dot();
      dot();
      dot();
      letter_pause();
      break;
    // I, i  ->  · · 
    case 'i':
      dot();
      dot();
      letter_pause();
      break;
    // J, j  ->  · − − − 
    case 'j':
      dot();
      dash();
      dash();
      dash();
      letter_pause();
      break;
    // K, k  ->  − · − 
    case 'k':
      dash();
      dot();
      dash();
      letter_pause();
      break;
    // L, l  ->  · − · · 
    case 'l':
      dot();
      dash();
      dot();
      dot();
      letter_pause();
      break;
    // M, m  ->  − − 
    case 'm':
      dash();
      dash();
      letter_pause();
      break;
    // N, n  ->  − ·
    case 'n':
      dash();
      dot();
      letter_pause();
      break;
    // O, o  ->  − − − 
    case 'o':
      dash();
      dash();
      dash();
      letter_pause();
      break;
    // P, p  ->  · − − · 
    case 'p':
      dot();
      dash();
      dash();
      dot();
      letter_pause();
      break;
    // Q, q  ->  − − · − 
    case 'q':
      dash();
      dash();
      dot();
      dash();
      letter_pause();
      break;
    // R, r  ->  · − · 
    case 'r':
      dot();
      dash();
      dot();
      letter_pause();
      break;
    // S, s  ->  · · · 
    case 's':
      dot();
      dot();
      dot();
      letter_pause();
      break;
    // T, t  ->  − 
    case 't':
      dash();
      letter_pause();
      break;
    // U, u  ->  · · − 
    case 'u':
      dot();
      dot();
      dash();
      letter_pause();
      break;
    // V, v  ->  · · · − 
    case 'v':
      dot();
      dot();
      dot();
      dash();
      letter_pause();
      break;
    // W, w  ->  · − − 
    case 'w':
      dot();
      dash();
      dash();
      letter_pause();
      break;
    // X, x  ->  − · · − 
    case 'x':
      dash();
      dot();
      dot();
      dash();
      letter_pause();
      break;
    // Y, y  ->  − · − − 
    case 'y':
      dash();
      dot();
      dash();
      dash();
      letter_pause();
      break;
    // Z, z  ->  − − · · 
    case 'z':
      dash();
      dash();
      dot();
      dot();
      letter_pause();
      break;
    // 0  ->  − − − − − 
    case '0':
      dash();
      dash();
      dash();
      dash();
      dash();
      letter_pause();
      break;
    // 1  ->  · − − − − 
    case '1':
      dot();
      dash();
      dash();
      dash();
      dash();
      letter_pause();
      break;
    // 2  ->  · · − − − 
    case '2':
      dot();
      dot();
      dash();
      dash();
      dash();
      letter_pause();
      break;
    // 3  ->  · · · − − 
    case '3':
      dot();
      dot();
      dot();
      dash();
      dash();
      letter_pause();
      break;
    // 4  ->  · · · · − 
    case '4':
      dot();
      dot();
      dot();
      dot();
      dash();
      letter_pause();
      break;
    // 5  ->  · · · · · 
    case '5':
      dot();
      dot();
      dot();
      dot();
      dot();
      letter_pause();
      break;
    // 6  ->  − · · · · 
    case '6':
      dash();
      dot();
      dot();
      dot();
      dot();
      letter_pause();
      break;
    // 7  ->  − − · · · 
    case '7':
      dash();
      dash();
      dot();
      dot();
      dot();
      letter_pause();
      break;
    // 8  ->  − − − · ·
    case '8':
      dash();
      dash();
      dash();
      dot();
      dot();
      letter_pause();
      break;
    // 9  ->  − − − − · 
    case '9':
      dash();
      dash();
      dash();
      dash();
      dot();
      letter_pause();
      break;
      
    // The space between words is seven units.
    case ' ':
      word_pause();
      break;
      
    // Period [.]  ->  · − · − · − 
    case '.':
      dot();
      dash();
      dot();
      dash();
      dot();
      dash();
      letter_pause();
      break;
    // Comma [,]  ->  − − · · − − 
    case ',':
      dash();
      dash();
      dot();
      dot();
      dash();
      dash();
      letter_pause();
      break;
    // Question Mark [?]  ->  · · − − · · 
    case '?':
      dot();
      dot();
      dash();
      dash();
      dot();
      dot();
      letter_pause();
      break;
    // Apostrophe [']  ->  · − − − − · 
    case '\'':
      dot();
      dash();
      dash();
      dash();
      dash();
      dot();
      letter_pause();
      break;
    // Exclamation Point [!]  ->  − · − · − − 
    case '!':
      dash();
      dot();
      dash();
      dot();
      dash();
      dash();
      letter_pause();
      break;
    // Slash/Fraction Bar [/]  ->  − · · − · 
    case '/':
      dash();
      dot();
      dot();
      dash();
      dot();
      letter_pause();
      break;
    // Parenthesis (Open)      ->  − · − − · 
    case '(':
      dash();
      dot();
      dash();
      dash();
      dot();
      letter_pause();
      break;
    // Parenthesis (Close)     ->  − · − − · − 
    case ')':
      dash();
      dot();
      dash();
      dash();
      dot();
      dash();
      letter_pause();
      break;
    // Ampersand [&]           ->  · − · · · 
    case '&':
      dot();
      dash();
      dot();
      dot();
      dot();
      letter_pause();
      break;
    // Colon [:]               ->  − − − · · ·
    case ':':
      dash();
      dash();
      dash();
      dot();
      dot();
      dot();
      letter_pause();
      break;
    // Semicolon [;]           ->  − · − · − · 
    case ';':
      dash();
      dot();
      dash();
      dot();
      dash();
      dot();
      letter_pause();
      break;
    // Double Dash [=]         ->  − · · · − 
    case '=':
      dash();
      dot();
      dot();
      dot();
      dash();
      letter_pause();
      break;
    // Plus sign [+]           ->  · − · − · 
    case '+':
      dot();
      dash();
      dot();
      dash();
      dot();
      letter_pause();
      break;
    // Hyphen, Minus Sign [-]  ->  − · · · · − 
    case '-':
      dash();
      dot();
      dot();
      dot();
      dot();
      dash();
      letter_pause();
      break;
    // Underscore [_]          ->  · · − − · − 
    case '_':
      dot();
      dot();
      dash();
      dash();
      dot();
      dash();
      letter_pause();
      break;
    // Quotation mark ["]      ->  · − · · − · 
    case '"':
      dot();
      dash();
      dot();
      dot();
      dash();
      dot();
      letter_pause();
      break;
    // Dollar sign [$]         ->  · · · − · · − 
    case '$':
      dot();
      dot();
      dot();
      dash();
      dot();
      dot();
      dash();
      letter_pause();
      break;
    // At Sign [@]             ->  · − − · − ·  
    case '@':
      dot();
      dash();
      dash();
      dot();
      dash();
      dot();
      letter_pause();
      break;
     
    default: 
      Serial.print("Don't recognize ");
      Serial.write(letter);
      Serial.println();
      Serial.println("Character not supported");
    break;     
  }
  
}

/* dot function */
void dot() {
  digitalWrite(LED_PIN,HIGH);
  digitalWrite(BUZZER_PIN,HIGH);
  delay(TIME_UNIT);
  pause();
}

/* dash function */
void dash() {
  digitalWrite(LED_PIN,HIGH);
  digitalWrite(BUZZER_PIN,HIGH);
  delay(TIME_UNIT * 3);
  pause();
}

/* pause between parts of the same letter - 1 unit */
void pause() {
  digitalWrite(LED_PIN,LOW);
  digitalWrite(BUZZER_PIN,LOW);
  delay(TIME_UNIT);
}

/* pause between different letters - 3 units */
void letter_pause() {
  digitalWrite(LED_PIN,LOW);
  digitalWrite(BUZZER_PIN,LOW);
  // only wait 2 beats because pause after each part
  delay(TIME_UNIT * 2);
}

/* pause between different words - 7 units */
void word_pause() {
  digitalWrite(LED_PIN,LOW);
  digitalWrite(BUZZER_PIN,LOW);
  // only wait 4 beats because pause after each letter
  delay(TIME_UNIT * 4);
}
