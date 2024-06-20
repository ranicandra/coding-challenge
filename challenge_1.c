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

//function to initialise the motor, motor set to LOW
void stepperInit()
{
    digitalWrite(PORTD, EN_PIN, FALSE); 
}

//function to step the motor 
void stepMotor(uninit32_t steps, uninit32_t delayTime, bool direction)
{
    digitalWrite(PORTD, DIR_PIN, direction); //set motor direction
    digitalWrite(PORTD, EN_PIN, TRUE); //then enable the motor 

    //motor steps with constaints 
    for (uninit32_t i = 0; i < steps; i ++)
    {
        digitalWrite(PORTD, STEP_PIN, TRUE); //motor step high 
        delay(delayTime); //wait 
        digitalWrite(PORTD, STEP_PIN, FALSE); //motor step low
        delay(delayTime); //wait 
    }

    //disable the motor 
    digitalWrite(PORTD, EN_PIN, FALSE); //value set to LOW (false)

}


int main()
{
    stepperInit();

    //read serial port
    char serialData_input;

    while (1)
    {
        serialData_input = serialPort_Read();

        switch (serialData_input)
        {
            //step forward
            case 'F':
                stepMotor(20,5,true);
                break;
            //step backward
            case 'B':
                stepMotor(20,5,false);
                break;
            
        }

    }
    return 0;
}


