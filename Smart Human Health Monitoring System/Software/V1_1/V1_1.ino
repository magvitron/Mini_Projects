#include "config.h"
#include "readSensor.h"
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  pinMode(PIN_DI_HEART_BEAT, INPUT);
  // Print a message to the LCD.
  lcd.setCursor(0, 0);
  lcd.print("Smart Human Hlth");
  lcd.setCursor(0, 1);
  lcd.print(" Monitoring Sys");
  delay(2000);
  lcd.clear();

  // initialize timer1
  noInterrupts();           // disable all interrupts
  //  attachInterrupt(0, interrupt_handler, HIGH);
  interrupts();             // enable all interrupts

}

void loop() {
  lcd.setCursor(0, 0);
  lcd.print("T:");
  lcd.print(readTemp());
  Serial.println(readTemp(), 1);
  lcd.print((char) 223);
  lcd.print("B:");
  heart_beat = pulseIn(PIN_DI_HEART_BEAT, HIGH);
  lcd.print(heart_beat);
  Serial.println(heart_beat, 1);

//  delay();
  // put your main code here, to run repeatedly:

}
