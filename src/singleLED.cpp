#include "singleLED.h"
#include "Arduino.h"

singleLed::singleLed(int pin){
    //make sure to use pwm ports here
    pinMode(pin,OUTPUT);
    digitalWrite(pin,LOW);
    _pin = pin;
}

void singleLed::update(){
    switch(runningFunction){
        case 0:
        break;
        case 1:
            patternSingle(arrP,speedp);
        break;
        
        case 4:
            blinkSingle(speedp);
        break;
        case 5:
            blinkRandomSingle(speedp,timep);
        break;
    }
}

void singleLed::setOnSingle(){
    runningFunction = 0;
    digitalWrite(_pin, HIGH);
}

void singleLed::setOffSingle(){
    runningFunction = 0;
    digitalWrite(_pin, LOW);
}

void singleLed::setRandomBlinkSingle(int minTime, int maxTime){
    runningFunction = 5;
    speedp = minTime;
    timep = maxTime;
}

void singleLed::setPatternSingle(int pattern[], int lengthArray){
    if (arrP != 0) {
    delete [] arrP;
    }
    arrP = new int [lengthArray];

    for(int i=0; i < lengthArray; i++){
        arrP[i] = pattern[i];
    }
    speedp = lengthArray;
    runningFunction = 1;
}

void singleLed::setBlinkSingle(int speed){
    runningFunction = 4;
    speedp = speed;
}

//function for pattern based blinking, first entry always turns the led high
void singleLed::patternSingle(int pattern[], int lengthArray){
    if(counter < lengthArray) {
        if(milOld == 0){
            milOld = millis();
            digitalWrite(_pin,HIGH);
        }
        if((milOld + pattern[counter]) < millis() ){
            milOld = millis();
            if(counter % 2 == 0){
                digitalWrite(_pin, LOW);
            }
            else{
                digitalWrite(_pin,HIGH);
            }
            counter++;
        }
    }
    else{
        counter = 0;
    }
}
/*
// simple breathing function
void singleLed::breathSingle(int speed){
    if((milOld + 1) < millis() ){
        milOld = millis();
        float it = 0;
        it = (exp(sin(millis()/(float)speed*PI)) - 0.36787944)*108.0;
        analogWrite(_pin, it);
    }
}

// simple flickering function
void singleLed::flickerSingle(int intMin, int intMax){
    if((milOld + 100) < millis()){
        milOld = millis();
        float it = 0;
        it = random(intMin,intMax);
        analogWrite(_pin, it);
    }
}

//overload for instant use
void singleLed::flickerSingle(){
    if((milOld + 100) < millis()){
        milOld = millis();
        float it = 0;
        it = random(80,255);
        analogWrite(_pin, it);
    }
}

//overload for speed controll
void singleLed::flickerSingle(int intMin, int intMax, int speed){
    if((milOld + speed) < millis()){
        milOld = millis();
        float it = 0;
        it = random(intMin,intMax);
        analogWrite(_pin, it);
    }
}
*/

// simple blinking function
void singleLed::blinkSingle(int speed){
    if ( (milOld + speed) < millis() ) {
        milOld = millis();
        if(ioBlink == false){
            digitalWrite(_pin,HIGH);
            ioBlink = true;
        }
        else{
            digitalWrite(_pin,LOW);
            ioBlink = false;
        }
    }
}

//overload to allow for async blinking
void singleLed::blinkSingle(int timeHigh, int timeLow){
    if(ioBlink == false){
        if( (milOld + timeHigh) < millis()){
            milOld = millis();
            digitalWrite(_pin,LOW);
            ioBlink = true;
        }
    }
    else{
        if((milOld + timeLow) < millis()){
            milOld = millis();
            digitalWrite(_pin,HIGH);
            ioBlink = false;
        }
    }
}

//blinking with randomised delay
void singleLed::blinkRandomSingle(int minTime, int maxTime){
    if((milOld + rndTemp) < millis()){
        milOld = millis();
        rndTemp = random(minTime, maxTime);
        if(ioBlink == false){
            digitalWrite(_pin,HIGH);
            ioBlink = true;
        }
        else{
            digitalWrite(_pin,LOW);
            ioBlink = false;
        }
    }
}