#define AI_TEMP_PIN A0
#define AI_PRESS_PIN A1
#define DI_BEAT_PIN 2
#define DO_LED_PIN A2

#define GPSTEST 1

#define READ_COUNT 50
#define VCC 5.0
#define ADC_COUNT (VCC/1024)
#include <LiquidCrystal.h>
#include <SoftwareSerial.h>
#include <TinyGPS.h>

volatile int pulse_counter = 0;
volatile int heart_beat = 0;
volatile int timer1_counter = 0;

const int rs = 8, en = 9, d4 = 10, d5 = 11, d6 = 12, d7 = 13;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
TinyGPS gps;
//D6 - 6 -tx
//D7 -7 -rx
SoftwareSerial ss(7, 6);//rx tx
