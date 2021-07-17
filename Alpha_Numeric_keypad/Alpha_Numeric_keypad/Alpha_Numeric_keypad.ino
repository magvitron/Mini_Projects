/**
   @file Alpha_Numeric_Keypad
   @breif Program for old scholl mobile typing in generic
   4 row 3 col number pad
   @author Manu krishnan magvitron@gmail.com
   @date 16-07-2021
*/
#define DEBUG 0
#define ARRAY_SIZE 24 /**Global array size*/
#define TIME_OUT 100 /**Time out for key press after this
  the key will asign the value*/
/*
  @version 1.0
  @author Alexander Brevig
*/
#include <Keypad.h>

enum KEYPAD_TYPE {
  ALPHA_KEYPAD = 0,
  UPPER_CASE_KEYPAD = 1,
  NUMERIC_KEYPAD = 2
};
/**Keypad HW setup start*/
const byte ROWS = 4; /*four rows*/
const byte COLS = 3; /*three columns*/
/**Alpha key pad*/
char ALPHA_keys[ROWS][COLS] = {
  {' ', 'a', 'd'},
  {'g', 'j', 'm'},
  {'p', 't', 'w'},
  {'*', ' ', '#'}
};
/**Numeric*/
char NUM_keys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};
byte rowPins[ROWS] = {15, 2, 4, 16}; /*connect to the row pinouts of the keypad*/
byte colPins[COLS] = {17, 5, 18}; /*connect to the column pinouts of the keypad*/
/**Keypad HW setup end*/

uint8_t keyPadMode = ALPHA_KEYPAD;
uint8_t arr_index = 0;
char GAC_Data[ARRAY_SIZE] = {0};
/**Create an object of keypad*/
Keypad Alphakeypad = Keypad( makeKeymap(ALPHA_keys), rowPins, colPins, ROWS, COLS );
Keypad Numkeypad = Keypad( makeKeymap(NUM_keys), rowPins, colPins, ROWS, COLS );
/**
  @bried Setup (arduino function)
  @param Nothing
  @return Nothing
*/
void setup() {
  Serial.begin(9600);
  Serial.println("Started");
  delay(1000);
}
/*
  @brief Check the type of keypad and return the key
  @param keypaMode as global (alpha , upper
         or nmeric
  @return char, the key value
*/

char get_Type_Key()
{
  char LC_key = 0;
  /**Check for the key pad*/
  if (keyPadMode == ALPHA_KEYPAD)
  {
    /**Diffrent object for alpha*/
    LC_key = Alphakeypad.getKey();/* Read the key*/
  }
  else if (keyPadMode == NUMERIC_KEYPAD)
  {
    /**Diffrent object keypad for num key*/
    LC_key = Numkeypad.getKey();/* Read the key*/
  }
  else if (keyPadMode == UPPER_CASE_KEYPAD)
  {
    LC_key = (Alphakeypad.getKey()); /** Read the key*/
    /**check if the key pad value is * this is
      required since we are offseting the key value and * is
      a control key which changes the key pad
    */
    if (LC_key && LC_key != '*')
    {
      /**offset 32 points for making it as upper case (reffer ASCCI table)      */
      LC_key -= 32;
    }
  }
  /***/
  return LC_key;
}
/**
  @breif Main loop
  @return Nothing
  @param Nothing
*/
void loop() {
  /**  Declare the variables  */
  uint8_t timeOutCount = 0;
  char key, tempKey, temp;
  uint8_t upCount = 2;
  /**  Get the key  */
  key = get_Type_Key();
  if (key)
  {
    /**Key pad debouncing*/
    delay(100);
    /** check for control keys (* -> chages the keypad layoyt) */
    if (key == '*')
    {
      /** Print the character array*/
      Serial.println(GAC_Data);
      /** Change the keypad mode*/
      keyPadMode++;
      /**Rest to ALPHA keypad prevent overflow*/
      if (keyPadMode > NUMERIC_KEYPAD)
      {
        keyPadMode = ALPHA_KEYPAD;
      }
      /**Reset the key variable, since its expired*/
      key = 0;
      /**Print the current mode*/
      Serial.print("Alpha=0, upper=1, numeric:2 Current :");
      Serial.println(keyPadMode);
      delay(500);
    }
    /**Control '#' for clearing the global array */
    else if (key == '#')
    {
      /** Print the array in memory*/
      Serial.println(GAC_Data);
      /**Clear the array */
      for (int count = 0; count < ARRAY_SIZE; count++)
      {
        GAC_Data[count] = 0;
      }
      Serial.println("Cleared");
    }
    else
    {
      /** If its not a control key, its an alpha numeric key */

      /** Save the key variabe*/
      tempKey = key;
      Serial.println(key);
      /** Check for p,w since in key pad this is 4 times , eg
        key pad 2 is abc but keypad 7 is pqrs so the increment count is diffrent
      */
      if ((key == 'p' || key == 'w' || key == 'P' || key == 'W'))
      {
        /** CHange the incremement count*/
        upCount = 3;
      }
      else if (key == ' ')
      {
        /** Check for the space bar key (0 and 1) and reset the upcount*/
        upCount = 0;
      }
      /**Check for numeric keypad, and we dont require increment here too */
      else if (keyPadMode == NUMERIC_KEYPAD)
      {
        upCount = 0;
      }
      /**Check for time out,(the time out variable is set at the top
        if the time out is expired, break and save the current key to the global array
      */
      while (TIME_OUT >= timeOutCount)
      {
#if DEBUG ==1
        Serial.println(timeOutCount);
#endif
        temp = get_Type_Key();
        if (temp)
        {
          /** Check if the user pressed the same key or not (if diffrent prevent the increment)*/
          if (temp != tempKey)
          {
            /** User pressed diffent key*/
            timeOutCount = TIME_OUT;
          } else {
            /** Incremnt key so here , the increment is done with ASCCI in mind, 'a' is 97 so
                if we increment it will be 98 -> 'b' 99 -> 'c'
            */
            key++;
            timeOutCount = 0;
            /** Reset to the initial value id it exceeds the upcount, #pad7,9 -> 4 time
              other keys 3 times */
            if (key - tempKey > upCount)
            {
              key = tempKey;
            }
            Serial.println(key);
          }
        }
        /**Delay for a small time 10ms */
        delay(10);
        /** Increment timeout*/
        timeOutCount++;
      }
#if DEBUG ==1
      Serial.println("Inserted to array");
#endif
      /** Save in gloabal array*/
      GAC_Data[arr_index] = key;
      arr_index++;
      /** Reset the arr_index of global array*/
      if (arr_index > ARRAY_SIZE)
        arr_index = 0;
      /**PRint the array*/
      Serial.println(GAC_Data);
    }
  }
}
/** End of file!*/
