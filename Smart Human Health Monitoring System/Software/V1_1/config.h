#define ANALOG_PIN A0
#define PIN_DI_HEART_BEAT 2

#define WINDOW_SIZE 5


#define READ_COUNT 50
#define VCC 5.0
#define ADC_COUNT (VCC/1024)
#include <LiquidCrystal.h>

volatile int pulse_counter = 0;
volatile int heart_beat = 0;
volatile int timer1_counter = 0;

const int rs = 8, en = 9, d4 = 10, d5 = 11, d6 = 12, d7 = 13;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
