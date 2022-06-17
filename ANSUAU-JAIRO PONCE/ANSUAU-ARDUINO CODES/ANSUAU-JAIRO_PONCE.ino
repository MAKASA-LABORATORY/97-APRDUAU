// C++ code
//
/*
  Keyboard

  Plays a pitch that changes based on a changing
  input circuit:
  * 3 pushbuttons from +5V to analog in 0 through
  3
  * 3 10K resistors from analog in 0 through 3 to
  ground
  * 8-ohm speaker on digital pin 8
*/
#include <Adafruit_LiquidCrystal.h>
#define disLed 13
#define conLed 12


Adafruit_LiquidCrystal lcd_1(0);
int pos = 0;

void setup()
{lcd_1.begin(16, 2);
  lcd_1.print("DISCONNECTED");
  pinMode(A0, INPUT);
  pinMode(8, OUTPUT);
  pinMode(A1, INPUT);
 pinMode(disLed, OUTPUT);
 pinMode(conLed, OUTPUT);
  
}

void loop()
{
  // if button press on A0 is detected
  if (digitalRead(A0) == HIGH) {
    lcd_1.clear();
    lcd_1.print("DISCONNECTED");
    tone(8, 440, 100); // play tone 57 (A4 = 440 Hz)
  digitalWrite(disLed, HIGH);
    delay(1000);
   digitalWrite(disLed, LOW);
  }
  // if button press on A1 is detected
  if (digitalRead(A1) == HIGH) {
    lcd_1.clear();
    lcd_1.print("CONNECTED");
    tone(8, 494, 100); // play tone 59 (B4 = 494 Hz)
    digitalWrite(conLed, HIGH);
    delay(1000);
   digitalWrite(conLed, LOW);
  }
  delay(10); // Delay a little bit to improve simulation performance
}
