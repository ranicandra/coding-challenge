#include <stdint.h> 

//declare constants for the GPIO pins 
#define PORTD 0 
#define STEP_PIN 0
#define DIR_PIN 1
#define EN_PIN 2

//assume some functions used for the motor stepper 
void digitalWrite (uint8_t port, uint8_t pin, bool value);
char serialPort_Read(); //bytes
void delay(uint32_t miliseconds); //ms

//function to initialise the motor, motor set to 0 
void stepperInit()
{
    digitalWrite(PORTD, EN_PIN, 0) //value set to LOW (false)
}

//function to step the motor 
void stepMotor()
{
    //set direction 

    //then enable the motor 

    //adjust the step 
    
}


