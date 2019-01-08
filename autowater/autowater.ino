
int soilCheckInterval = 1000; //value for reading interval in ms

//values for storing moisture values
int readSoil();
int valBlue = 0;
int valRed = 0;
int valPurple = 0;
int valGreen = 0;
 
//Declare variables for the soil moisture sensor 
int soilPinBlue = A0;
int soilPinRed = A1;
int soilPinPurple = A2;
int soilPinGreen = A3;

//Variables for Soil moisture Power
int soilPowerBlue = 6;
int soilPowerRed = 7;
int soilPowerPurple = 8; 
//pin 9,10,11 reserved for indicator LED
int soilPowerGreen = 12;

//Relay and Solenoid control for pump and valve
int pumpPwr = 13;
int flowPinBlue = 2;
int flowPinRed = 3;
int flowPinPurple = 4;
int flowPinGreen = 5;

//Digital read from flowPin's for debugging
int relayStateBlue;
int relayStateRed;
int relayStatePurple;
int relayStateGreen;

//minimum and maximum moisture values to trigger pump and solenoid
const int blueOn = 999;
const int blueOff = 600;
const int redOn = 999;
const int redOff = 600;
const int PurpleOn = 999;
const int PurpleOff = 600;
const int greenOn = 999;
const int greenOff = 600;


//Begin feedback variables
int greenLEDPin = 9;    // LED connected to digital pin 9
int redLEDPin = 10;     // LED connected to digital pin 10
int blueLEDPin = 11;    // LED connected to digital pin 11

int indicateBlue = 0;
int indicateRed = 0;
int indicatePurple = 0;
int indicateGreen = 0;


void setColor(int red, int green, int blue)
{
  #ifdef COMMON_ANODE
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
  #endif
  analogWrite(redLEDPin, red);
  analogWrite(greenLEDPin, green);
  analogWrite(blueLEDPin, blue);  
} 

//Rather than powering the sensor through the 3.3V or 5V pins, 
//we'll use a digital pin to power the sensor. This will 
//prevent corrosion of the sensor as it sits in the soil. 
void setup() 
{
  Serial.begin(9600);   // open serial over USB

  //pinMode(indicatorLED, OUTPUT); //LED to indicate reading / pumping status
  
  pinMode(soilPowerBlue, OUTPUT);//Set D7 as an OUTPUT
  pinMode(flowPinBlue, OUTPUT);//Set D3 as OUTPUT
  digitalWrite(soilPowerBlue, LOW);//Set to LOW so no power is flowing through the sensor
  digitalWrite(flowPinBlue, LOW);//Set to LOW Relay & solenoid for pump(off) and valve(closed) 

  pinMode(soilPowerRed, OUTPUT);//Set D8 as an OUTPUT
  pinMode(flowPinRed, OUTPUT);//Set D4 as OUTPUT
  digitalWrite(soilPowerRed, LOW);//Set to LOW so no power is flowing through the sensor
  digitalWrite(flowPinRed, LOW);//Set to LOW Relay & solenoid for pump(off) and valve(closed) 

  pinMode(soilPowerPurple, OUTPUT);//Set D9 as an OUTPUT
  pinMode(flowPinPurple, OUTPUT);//Set D5 as OUTPUT
  digitalWrite(soilPowerPurple, LOW);//Set to LOW so no power is flowing through the sensor
  digitalWrite(flowPinPurple, LOW);//Set to LOW Relay & solenoid for pump(off) and valve(closed) 

  pinMode(soilPowerGreen, OUTPUT);//Set D10 as an OUTPUT
  pinMode(flowPinGreen, OUTPUT);//Set D6 as OUTPUT
  digitalWrite(soilPowerGreen, LOW);//Set to LOW so no power is flowing through the sensor
  digitalWrite(flowPinGreen, LOW);//Set to LOW Relay & solenoid for pump(off) and valve(closed)
}

void loop(){
delay(soilCheckInterval);//take a reading every x ms's
}
//This is a function used to get the soil moisture content
int readSoil()
{
    delay(soilCheckInterval);//take a reading every x ms's

    setColor(100,100,100);

    digitalWrite(soilPowerBlue, HIGH);//turn D7 "On"
    digitalWrite(soilPowerRed, HIGH);//turn D8 "On"
    digitalWrite(soilPowerPurple, HIGH);//turn D9 "On"
    digitalWrite(soilPowerGreen, HIGH);//turn D10 "On"
    
    delay(10);//wait 10 milliseconds
     
    valBlue = analogRead(soilPinBlue);//Read the SIG value form sensor
    valRed = analogRead(soilPinBlue);//Read the SIG value form sensor
    valPurple = analogRead(soilPinBlue);//Read the SIG value form sensor
    valGreen = analogRead(soilPinBlue);//Read the SIG value form sensor 
    
    digitalWrite(soilPowerBlue, LOW);//turn D7 "Off"
    digitalWrite(soilPowerRed, LOW);//turn D8 "Off"
    digitalWrite(soilPowerPurple, LOW);//turn D9 "Off"
    digitalWrite(soilPowerGreen, LOW);//turn D10 "Off"
    delay(1000);//keep LED on for 1 sec
    setColor(0,0,0);//turn LED off

    
    return valBlue;//send current moisture value
    return valRed;//send current moisture value
    return valPurple;//send current moisture value
    return valGreen;//send current moisture value




if (valBlue > blueOn) 
{
      digitalWrite(flowPinBlue, HIGH);   // turn the relay on 
      indicateBlue = 1;
}
if (valBlue < blueOff) 
{
      digitalWrite(flowPinBlue, LOW);    // turn the relay off 
      indicateBlue = 0;
}
if (valRed > redOn) 
{
      digitalWrite(flowPinBlue, HIGH);   // turn the relay on 
      indicateRed = 1;
}
if (valRed < redOff) 
{
      digitalWrite(flowPinBlue, LOW);    // turn the relay off 
      indicateRed = 0;
}
if (valPurple > PurpleOn) 
{
      digitalWrite(flowPinBlue, HIGH);   // turn the relay on 
      indicatePurple = 1;
}
if (valPurple < PurpleOff) 
{
      digitalWrite(flowPinBlue, LOW);    // turn the relay off 
      indicatePurple = 0;
}
if (valGreen > greenOn) 
{
      digitalWrite(flowPinBlue, HIGH);   // turn the relay on 
      indicateGreen = 1;
}
if (valGreen < greenOff) 
{
      digitalWrite(flowPinBlue, LOW);    // turn the relay off 
      indicateGreen = 0;
}
if ((indicateBlue + indicateRed + indicatePurple + indicateGreen) > 0)
{
       digitalWrite(pumpPwr, HIGH);
}      
else
{
       digitalWrite(pumpPwr, LOW);
}     

//Begin indicator light for pump / solenoid
if (indicateBlue = 1) {
      setColor(0,0,255);
      delay(500);
      setColor(0,0,0);
}
if (indicateRed = 1) {
      setColor(0,0,255);
      delay(500);
      setColor(0,0,0);
}
if (indicatePurple = 1) {
      setColor(0,0,255);
      delay(500);
      setColor(0,0,0);
}
if (indicateGreen = 1) {
      setColor(0,0,255);
      delay(500);
      setColor(0,0,0);
}
setColor(0,0,0);

relayStateBlue = digitalRead(flowPinBlue);
relayStateRed = digitalRead(flowPinRed);
relayStatePurple = digitalRead(flowPinPurple);
relayStateGreen = digitalRead(flowPinGreen);

     
//Serial Monitor debugging
Serial.print("Soil Moisture = ");    
//get soil moisture value from the function below and print it
Serial.println(readSoil());
Serial.print ("Relay state ");
Serial.println (relayStateBlue);
}
