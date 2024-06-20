# coding-challenge
Taggle Coding Challenge

1_challenge_1
    
    Requirements: 
    - A bi-polar stepper motor (GPIO pins connected to Port D (pins 0,1,2))
    - The motor has 20 steps per revolution (18 degrees per step), not more than 600 RPM
    - Controller runs at 7MHz & GPIO subsys takes 3 clock cycles 
    - ARM Cortex M0 has limited resources with 4KB RAM & 32 KB Flash

    Assumptions:
    - Availability of API (digitalWrite)
    - Reading Serial Port 

    Functions Assumptions: 
    - example: digitalWrite(PortD, 0, HIGH), function: digitalWrite (Port, Pin, Value)
    - serialPort_Read()
    - delay () //to count the timing for the stepper motor 

    Calc: 
    1 minute = max 12000 steps 
    1 sec = max 200 steps/sec
    1 step = 5ms/step
    
    Reference: https://learn.sparkfun.com/tutorials/easy-driver-hook-up-guide



