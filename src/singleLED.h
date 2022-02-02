/* Based on singleLEDLibrary but not included as a library to be able to streamline the code to our needs
*
*singleLEDLibrary
* A library for non interupting lighting effects for single LED's
* Pim Ostendorf - 2017.11.24
*/

#ifndef singleLED_h
#define singleLED_h
#include "Arduino.h"

class singleLed
{
    public:
    //public variables and fucntions
        singleLed(int pin);

        //blink
        void blinkSingle(int speed);
        void blinkSingle(int timeHigh, int timeLow);
        void blinkRandomSingle(int minTime, int maxTime);
        
               
        //blink pattern
        void patternSingle(int pattern[], int speed);
        
        //future update function
        void update();
        void setPatternSingle(int pattern[], int lenghtarray);
        void setBreathSingle(int speed);
        void setFlickerSingle();
        void setBlinkSingle(int speed);
        void setRandomBlinkSingle(int minTime, int maxTime);
        void setOnSingle();
        void setOffSingle();
        
    private:
    //private variables and fucntion
        //gobal variables
        int _pin;
        unsigned long milOld;
        int runningFunction = 0;
        int speedp;
        int timep;
        //int pPatt[];
        int* arrP = 0;

        //variables for blinking
        bool ioBlink = false;
        int rndTemp = 0;

        //variables for pattern
        int counter = 0;
};

#endif