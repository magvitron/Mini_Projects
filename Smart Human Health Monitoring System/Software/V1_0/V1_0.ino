#include "config.h"
#include "gps.h"
#include "readSensor.h"
/**
   @breif initialize all
   @return None
   @param None
*/
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.setCursor(0, 0);
  lcd.print("Smart Human Hlth");
  lcd.setCursor(0, 1);
  lcd.print(" Monitoring Sys");
  delay(500);
  lcd.clear();
  pinMode(DI_BEAT_PIN, INPUT);
  pinMode(DO_LED_PIN, OUTPUT);
  // initialize timer1
  noInterrupts();           // disable all interrupts
  attachInterrupt(0, interrupt_handler, HIGH);
  TCCR1A = 0;
  TCCR1B = 0;

  // Set timer1_counter to the correct value for our interrupt interval
  //timer1_counter = 64911;   // preload timer 65536-16MHz/256/100Hz
  //timer1_counter = 64286;   // preload timer 65536-16MHz/256/50Hz
  timer1_counter = 34286;   // preload timer 65536-16MHz/256/2Hz

  TCNT1 = timer1_counter;   // preload timer
  TCCR1B |= (1 << CS12);    // 256 prescaler
  TIMSK1 |= (1 << TOIE1);   // enable timer overflow interrupt
  interrupts();             // enable all interrupts
#if GPSTEST ==1
  Serial.println("Sats HDOP Latitude  Longitude  Fix  Date       Time     Date Alt    Course Speed Card  Distance Course Card  Chars Sentences Checksum");
  Serial.println("          (deg)     (deg)      Age                      Age  (m)    --- from GPS ----  ---- to London  ----  RX    RX        Fail");
  Serial.println("-------------------------------------------------------------------------------------------------------------------------------------");
#endif
  ss.begin(9600);
}
/**
   @breif ISR timer one overflow flag
   @return None
   @param None
*/
ISR(TIMER1_OVF_vect)        // interrupt service routine
{
  TCNT1 = timer1_counter;   // preload timer
  heart_beat = pulse_counter * 60;
  pulse_counter = 0;
}
/**
   @breif ISR for pin#2
   @return None
   @param None
*/
void interrupt_handler()
{
  pulse_counter += 1;
}
/**
   @breif Loop
   @return None
   @param None
*/
void loop() {
  digitalWrite(DO_LED_PIN, HIGH);
  /* temperature*/
  lcd.setCursor(0, 0);
  lcd.print("T:");
  lcd.print(readTemp());
  lcd.print((char) 223);
  /* heart beat*/
  lcd.print("B:");
  lcd.print(heart_beat);
  lcd.print("BPM");
  /* pressure */
  lcd.setCursor(0, 1);
  lcd.print("P:");
  lcd.print(readPress());
  lcd.print("mmHg");
  /* */
  readGPS();
  char  charbuf[30];
  sprintf(charbuf, "https://blynk.io/T%d_P%d_B%d", (int)readTemp(), (int)readPress(),(int) heart_beat);
  Serial.println("--------------Sending data-------------------");
  Serial.println(charbuf);
  Serial.println("------------------Done-----------------------");
  //  Serial.print("T:");
  delay(100);
  digitalWrite(DO_LED_PIN, LOW);

#if 0
  //  Serial.print(
  Serial.println(readTemp(), 1);
#endif
}
