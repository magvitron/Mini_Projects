#include <Keypad.h>
#define DEBUG 1
#define ARRAY_SIZE 24

#define TIME_OUT 50
enum KEYPAD_TYPE {
  ALPHA_KEYPAD = 0,
  UPPER_CASE_KEYPAD = 1,
  NUMERIC_KEYPAD = 2
};

const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns

char ALPHA_keys[ROWS][COLS] = {
  {' ', 'a', 'd'},
  {'g', 'j', 'm'},
  {'p', 't', 'w'},
  {'*', ' ', '#'}
};
char NUM_keys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};

byte rowPins[ROWS] = {11, 12, 13, A0}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {10, 9, 8}; //connect to the column pinouts of the keypad
uint8_t keyPadMode = ALPHA_KEYPAD;

uint8_t index = 0;
char GAC_Data[ARRAY_SIZE] = {0};
//Create an object of keypad
Keypad Alphakeypad = Keypad( makeKeymap(ALPHA_keys), rowPins, colPins, ROWS, COLS );
Keypad Numkeypad = Keypad( makeKeymap(NUM_keys), rowPins, colPins, ROWS, COLS );
void setup() {
  Serial.begin(9600);
  Serial.println("Started");
}
/*
   get the typf of key

*/

char get_Type_Key()
{
  char LC_key = 0;
  if (keyPadMode == ALPHA_KEYPAD)
  {
    LC_key = Alphakeypad.getKey();// Read the key
  }
  else if (keyPadMode == NUMERIC_KEYPAD)
  {
    LC_key = Numkeypad.getKey();// Read the key
  }
  else if (keyPadMode == UPPER_CASE_KEYPAD)
  {
    LC_key = (Alphakeypad.getKey()); // Read the key
    if (LC_key && LC_key != '*')
    {
      LC_key -= 32;
    }
  }
  return LC_key;
}

void loop() {
  uint8_t timeOutCount = 0;
  char key, tempKey, temp;
  uint8_t upCount = 2;
  key = get_Type_Key();
  if (key)
  {
    if (key == '*')
    {
      Serial.println(GAC_Data);
      keyPadMode++;
      if (keyPadMode > NUMERIC_KEYPAD)
      {
        keyPadMode = ALPHA_KEYPAD;
      }
      delay(500);
      key = 0;
      Serial.print("Alpha=0, upper=1, numeric:2 Current :");
      Serial.println(keyPadMode);
    }
    else if (key == '#')
    {
      Serial.println(GAC_Data);
      for (int count = 0; count < ARRAY_SIZE; count++)
      {
        GAC_Data[count] = 0;
      }
      Serial.println("Cleared");
    }
    else
    {
      tempKey = key;
      Serial.println(key);
      if ((key == 'p' || key == 'w' || key == 'P' || key == 'W'))
      {
        upCount = 3;
      }
      else if (key == ' ')
      {
        upCount = 0;
      }
      else if (keyPadMode == NUMERIC_KEYPAD)
      {
        upCount = 0;
      }
      while (TIME_OUT >= timeOutCount)
      {
        temp = get_Type_Key();
        if (temp)
        {
          if (temp != tempKey)
          {
            timeOutCount = TIME_OUT;
          } else {
            key++;
            timeOutCount = 0;
            if (key - tempKey > upCount)
            {
              key = tempKey;
            }
            Serial.println(key);
          }
        }

        delay(10);
        timeOutCount++;
      }
      GAC_Data[index] = key;
      index++;
      if (index > ARRAY_SIZE)
        index = 0;
      Serial.println(GAC_Data);
    }
  }
}
