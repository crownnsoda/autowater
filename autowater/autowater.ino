
int soilCheckInterval = 1000 //value for reading interval in ms


int greenLEDPin = 9;    // LED connected to digital pin 9
int redLEDPin = 10;     // LED connected to digital pin 10
int blueLEDPin = 11;    // LED connected to digital pin 11

int redValue = 0; // value to write to the red LED
int greenValue = 0; // value to write to the green LED
int blueValue = 0; // value to write to the blue LED

//values for storing moisture values
int valBlue = 0;
int valRed = 0;
int valYellow = 0;
int valGreen = 0;
 
//Declare variables for the soil moisture sensor 
int soilPinBlue = A0;
int soilPinRed = A1;
int soilPinYellow = A2;
int soilPinGreen = A3;

//Variables for Soil moisture Power
int soilPowerBlue = 6;
int soilPowerRed = 7;
int soilPowerYellow = 8; 
//pin 9,10,11 reserved for indicator LED
int soilPowerGreen = 12;

//Relay and Solenoid control for pump and valve
int flowPinBlue = 2;
int flowPinRed = 3;
int flowPinYellow = 4;
int flowPinGreen = 5;

//Digital read from flowPin's for debugging
int relayStateBlue;
int relayStateRed;
int relayStateYellow;
int relayStateGreen;

//minimum and maximum moisture values to trigger pump and solenoid
const int blueOn = 999;
const int blueOff = 600;
const int redOn = 999;
const int redOff = 600;
const int yellowOn = 999;
const int yellowOff = 600;
const int greenOn = 999;
const int greenOff = 600;

//Rather than powering the sensor through the 3.3V or 5V pins, 
//we'll use a digital pin to power the sensor. This will 
//prevent corrosion of the sensor as it sits in the soil. 

void setup() 
{
  Serial.begin(9600);   // open serial over USB

  pinMode(indicatorLED, OUTPUT); //LED to indicate reading / pumping status
  
  pinMode(soilPowerBlue, OUTPUT);//Set D7 as an OUTPUT
  pinMode(flowPinBlue, OUTPUT);//Set D3 as OUTPUT
  digitalWrite(soilPowerBlue, LOW);//Set to LOW so no power is flowing through the sensor
  digitalWrite(flowPinBlue, LOW);//Set to LOW Relay & solenoid for pump(off) and valve(closed) 

  pinMode(soilPowerRed, OUTPUT);//Set D8 as an OUTPUT
  pinMode(flowPinRed, OUTPUT);//Set D4 as OUTPUT
  digitalWrite(soilPowerRed, LOW);//Set to LOW so no power is flowing through the sensor
  digitalWrite(flowPinRed, LOW);//Set to LOW Relay & solenoid for pump(off) and valve(closed) 

  pinMode(soilPowerYellow, OUTPUT);//Set D9 as an OUTPUT
  pinMode(flowPinYellow, OUTPUT);//Set D5 as OUTPUT
  digitalWrite(soilPowerYellow, LOW);//Set to LOW so no power is flowing through the sensor
  digitalWrite(flowPinYellow, LOW);//Set to LOW Relay & solenoid for pump(off) and valve(closed) 

  pinMode(soilPowerGreen, OUTPUT);//Set D10 as an OUTPUT
  pinMode(flowPinGreen, OUTPUT);//Set D6 as OUTPUT
  digitalWrite(soilPowerGreen, LOW);//Set to LOW so no power is flowing through the sensor
  digitalWrite(flowPinGreen, LOW);//Set to LOW Relay & solenoid for pump(off) and valve(closed) 
}

void loop() 
{
//Serial Monitor debugging
Serial.print("Soil Moisture = ");    
//get soil moisture value from the function below and print it
Serial.println(readSoil());
Serial.print ("Relay state ");
Serial.println (relayStateBlue);


delay(soilCheckInterval);//take a reading every second
digitalWrite(pin, value);
if (valBlue > blueOn) {
      digitalWrite(flowPinBlue, HIGH);   // turn the relay on (HIGH is the voltage level)
      delay(5000) //minimum run time 5 secs
}
if (valBlue < blueOff) {
      digitalWrite(flowPinBlue, LOW);    // turn the relay off by making the voltage LOW

}      
{relayState = digitalRead(flowPinBlue);
}
}
//This is a function used to get the soil moisture content
int readSoil()
{

    digitalWrite(soilPowerBlue, HIGH);//turn D7 "On"
    digitalWrite(soilPowerRed, HIGH);//turn D8 "On"
    digitalWrite(soilPowerYellow, HIGH);//turn D9 "On"
    digitalWrite(soilPowerGreen, HIGH);//turn D10 "On"
    
    delay(10);//wait 10 milliseconds
     
    valBlue = analogRead(soilPinBlue);//Read the SIG value form sensor
    valRed = analogRead(soilPinBlue);//Read the SIG value form sensor
    valYellow = analogRead(soilPinBlue);//Read the SIG value form sensor
    valGreen = analogRead(soilPinBlue);//Read the SIG value form sensor 

    
    digitalWrite(soilPowerBlue, LOW);//turn D7 "Off"
    digitalWrite(soilPowerRed, LOW);//turn D8 "Off"
    digitalWrite(soilPowerYellow, LOW);//turn D9 "Off"
    digitalWrite(soilPowerGreen, LOW);//turn D10 "Off"

    
    return valBlue;//send current moisture value
    return valRed;//send current moisture value
    return valYellow;//send current moisture value
    return valGreen;//send current moisture value



}
