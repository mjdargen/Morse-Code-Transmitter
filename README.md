# Morse Code Transmitter
*Michael D'Argenio   
mjdargen@gmail.com  
https://dargen.io
https://github.com/mjdargen  
September 19, 2019*  
\
Takes input from the serial port and converts it
to Morse Code. Blinks an LED and buzzes an active
buzzer to signal the Morse Code.  
\
**LED: visual morse code representation**
* Digital output pin 2
* Has 220 ohm series resistor
* Lights up every time there is a dot or dash

**Active Buzzer: auditory morse code representation**  
* Digital output pin 3
* Has 100 ohm series resistor to limit volume
* Beeps every time there is a dot or dash

**International Morse Code**
1. The length of a dot is one unit.
2. A dash is three units.
3. The space between parts of the same letter is one unit.
4. The space between letters is three units.
5. The space between words is seven units.    


[//]: # (Hello)  
      

<p align="center">
  <img src="https://github.com/mjdargen/Morse-Code-Transmitter/blob/master/morsecode_bb.png" width="600">
</p>

<p align="center">
  <img src="https://github.com/mjdargen/Morse-Code-Transmitter/blob/master/morsecode_schem.png" width="600">
</p>


[//]: # (Hello)  
      
|Category      |  Character                 |  Code                 |  
| ------------ |:--------------------------:| ---------------------:|
|Letters       |  A, a                      |  · −                  |  
|Letters       |  B, b                      |  − · · ·              |  
|Letters       |  C, c                      |  − · − ·              |  
|Letters       |  D, d                      |  − · ·                |  
|Letters       |  E, e                      |  ·                    |  
|Letters       |  F, f                      |  · · − ·              |  
|Letters       |  G, g                      |  − − ·                |  
|Letters       |  H, h                      |  · · · ·              |  
|Letters       |  I, i                      |  · ·                  |  
|Letters       |  J, j                      |  · − − −              |  
|Letters       |  K, k                      |  − · −                |  
|Letters       |  L, l                      |  · − · ·              |  
|Letters       |  M, m                      |  − −                  |  
|Letters       |  N, n                      |  − ·                  |  
|Letters       |  O, o                      |  − − −                |  
|Letters       |  P, p                      |  · − − ·              |  
|Letters       |  Q, q                      |  − − · −              |  
|Letters       |  R, r                      |  · − ·                |  
|Letters       |  S, s                      |  · · ·                |  
|Letters       |  T, t                      |  −                    |  
|Letters       |  U, u                      |  · · −                |  
|Letters       |  V, v                      |  · · · −              |  
|Letters       |  W, w                      |  · − −                |  
|Letters       |  X, x                      |  − · · −              |  
|Letters       |  Y, y                      |  − · − −              |  
|Letters       |  Z, z                      |  − − · ·              |  
|Numbers       |  0                         |  − − − − −            |  
|Numbers       |  1                         |  · − − − −            |  
|Numbers       |  2                         |  · · − − −            |  
|Numbers       |  3                         |  · · · − −            |  
|Numbers       |  4                         |  · · · · −            |  
|Numbers       |  5                         |  · · · · ·            |  
|Numbers       |  6                         |  − · · · ·            |  
|Numbers       |  7                         |  − − · · ·            |  
|Numbers       |  8                         |  − − − · ·            |  
|Numbers       |  9                         |  − − − − ·            |  
|Punctuation   |  Period [.]                |  · − · − · −          |  
|Punctuation   |  Comma [,]                 |  − − · · − −          |  
|Punctuation   |  Question Mark [?]         |  · · − − · ·          |  
|Punctuation   |  Apostrophe [']            |  · − − − − ·          |  
|Punctuation   |  Exclamation Point [!]     |  − · − · − −          |  
|Punctuation   |  Slash/Fraction Bar [/]    |  − · · − ·            |  
|Punctuation   |  Parenthesis (Open)        |  − · − − ·            |  
|Punctuation   |  Parenthesis (Close)       |  − · − − · −          |  
|Punctuation   |  Ampersand [&]             |  · − · · ·            |  
|Punctuation   |  Colon [:]                 |  − − − · · ·          |  
|Punctuation   |  Semicolon [;]             |  − · − · − ·          |  
|Punctuation   |  Double Dash [=]           |  − · · · −            |  
|Punctuation   |  Plus sign [+]             |  · − · − ·            |  
|Punctuation   |  Hyphen, Minus Sign [-]    |  − · · · · −          |  
|Punctuation   |  Underscore [_]            |  · · − − · −          |  
|Punctuation   |  Quotation mark ["]        |  · − · · − ·          |  
|Punctuation   |  Dollar sign [$]           |  · · · − · · −        |  
|Punctuation   |  At Sign [@]               |  · − − · − ·          |  
