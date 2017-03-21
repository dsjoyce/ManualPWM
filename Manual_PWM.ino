
#define DELAY_CYCLES(n) __builtin_avr_delay_cycles(n)

//define lights on and off durations
//Clock speed is 16000000(16 MHz) in the Arduino Uno, 16*10^6 cycles is 1 s
//DELAY_CYCLES throws an error if CyclesOff is not a const int
//If we want 1000 Hz PWM frequency then that would contain 16000 cycles
const int NCycles = 16000;
//As this value increases,the brightness should increase.  
//Values are 160 (1%) 800 (5%) 1600 (10%) 3200 (20%) 6400 (40%) 8000 (50%) 
//9600 (60%) 12800 (80%)  14400 (90%) 16000 (100%)
const int CyclesOn = 160; 
const int CyclesOff = NCycles - CyclesOn;


int ISI1 = 1;
int ISI2 = 1;

void setup() 
{
// Initialize digital pin 12 as LED output
pinMode(12,OUTPUT);
//Initialise pin 3 which can do PWM
pinMode(3,OUTPUT);
//Turn off interrupts to minimize jitter
cli();
//Allows logging to serial monitor window
Serial.begin(9600);
}

void loop() 
{
//Swith on the light, then off
//Could technically
//Serial.print (micros());
//Serial.println();
PORTB |= B00010000; // on PIN 12
//Serial.print (micros());
//Serial.println();
DELAY_CYCLES(CyclesOn);
PORTB &= B11101111; // on PIN 12
DELAY_CYCLES(CyclesOff);
}
