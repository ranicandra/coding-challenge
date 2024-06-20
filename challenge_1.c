#include <stdint.h> 
#include <stdbool.h>
#include <stdio.h>

//declare constants for the GPIO pins 
#define PORTD 0 
#define STEP_PIN 0
#define DIR_PIN 1 
#define EN_PIN 2 
#define MS1_PIN 3 //MS1 pin is tied to GND (low)
#define MS2_PIN 4 //MS2 pin is tied to GND (low)

//assume some functions used for the motor stepper 
void digitalWrite (uint8_t port, uint8_t pin, bool value);
char serialPort_Read(); // bytes
void delay(uint32_t miliseconds); // ms

//function to initialise the motor, motor set to LOW
void stepperInit()
{
    digitalWrite(PORTD, EN_PIN, false); 
}

//function to step the motor 
void stepMotor(uint32_t steps, uint32_t delayTime, bool directionForward)
{
    digitalWrite(PORTD, DIR_PIN, directionForward); //set motor direction
    digitalWrite(PORTD, EN_PIN, true); //then enable the motor 

    //motor steps with constaints 
    for (uint32_t i = 0; i < steps; i ++)
    {
        digitalWrite(PORTD, STEP_PIN, true); //motor step high 
        delay(delayTime); //wait 
        digitalWrite(PORTD, STEP_PIN, false); //motor step low
        delay(delayTime); //wait 
    }

    //disable the motor 
    digitalWrite(PORTD, EN_PIN, false); //value set to LOW (false)

}


int main()
{
    stepperInit();

    //Read serial port
    char serialData_input;

    while (1)
    {
        serialData_input = serialPort_Read(); //Read input from serial port

        switch (serialData_input)
        {
            case 'F': //step forward
                stepMotor(20,5,true);
                break;
            case 'B': //step backward
                stepMotor(20,5,false);
                break;
            default:
                printf("Unknown input: %c\n", serialData_input); //print unknown serial data read
                break;
        }

    }
    return 0;
}

//Assume APIs with empty routines for the sake of completeness
void digitalWrite (uint8_t port, uint8_t pin, bool value)
{
    //Dummy implementation 
    printf("Setting Port %d pin %d to %s\n", port, pin, value ? "HIGH" : "LOW");
}
char serialPort_Read()
{
    //Dummy implementation
    static char inputs[] = {'F', 'B', 'X'};
    static int index = 0; 
    char input = inputs[index];
    index = (index + 1) %3; //Cycle through 'F','B', and 'X'
    return input;
}
void delay(uint32_t miliseconds)
{
    //dummy implementation 
    printf("Delaying for %d ms\n", miliseconds);
}



