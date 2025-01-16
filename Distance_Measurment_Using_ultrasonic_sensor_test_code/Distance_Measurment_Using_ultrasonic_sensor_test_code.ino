/*  Distance Measuement Using UltraSonic Sensor 
 *  SJV ATAL Project
 *  Code Written By Mr.Ayan das
 *  Date 15/01/2023
 *  FramWork Version 0.0.9
*/


#include <LiquidCrystal_I2C.h> // Library for I2C 
#include <Wire.h>              // Library for I2C communication
//========================================================================================
LiquidCrystal_I2C lcd(0x27,16,2); //LCD  Address default 16*2
//========================================================================================
#define echoPin 11    // attach pin D2 Arduino to pin Echo of JSN-SR04T
#define trigPin 12    //attach pin D3 Arduino to pin Trig of JSN-SR04T
//========================================================================================
uint8_t Arrow[8] = {0x0, 0x04 ,0x06, 0x1f, 0x06, 0x04, 0x00, 0x00};   //This Part Make "Binary Vector Arrow Symbol"
uint8_t Heart[8] = {0x0,0xa,0x1f,0x1f,0xe,0x4,0x0};                   //This part make "Binary Vector Heart Symbol" 
//========================================================================================
                           // defines variables
                      
long duration;              // variable for the duration of sound wave travel
long int distanceCM;        // variable for the distance measurement CM

float distanceIn;           // variable for the distance measurement Inch
float distanceInch;         // variable for the distance measurement Inch

//========================================================================================
void setup(void) {                 //  Void setup funcation is one time  initialization
  Serial.begin(9600);              // Serial Communication is starting with 9600 of baud rate speed
//======================================================================================== 
  lcd.init();                      // initialize the lcd  
  lcd.clear();                     // LCD Display data 'Clear'
  lcd.backlight();                 // Background LED turn On
//======================================================================================== 
  lcd.createChar(0, Arrow);        // Inseart the "Binary Vector ArroW" symbol
  lcd.createChar(1, Heart);        // Inseart the "Binary Vector Heart" symbol
  lcd.home();                      // Home the LCD
  
//========================================================================================
                                 // Print a message to the LCD.           
                                                  
  pinMode(trigPin, OUTPUT);      // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT);       // Sets the echoPin as an INPUT
//========================================================================================
  lcd.clear();                   // Default data Clear
  lcd.setCursor(3,0);            // set cursor 3 colum 0 row
  lcd.print("WELCOME TO");       // print some text in LCD
  Serial.println("WELCOME TO");  // print some text in Serial Monitor
    lcd.setCursor(3,1);          // set cursor 3 colum 1 row
    lcd.write(1);                // Binary Vector Heart Symbol Print
    lcd.setCursor(4,1);          // set cursor 4 colum 1 row
    lcd.print("SJV ATAL");       // print some text in LCD
    Serial.println("SJV ATAL");  // print some text in Serial Monitor
    lcd.setCursor(12,1);         // set cursor 12 colum 1 row
    lcd.write(1);                // Binary Vector Heart Symbol Print
    delay(3000);                 // Delay 3 sec
    lcd.clear();                 // LCD Display data 'Clear
//========================================================================================     
Serial.println("Distance Measuement Using UltraSonic Sensor"); // print some text in Serial Monitor
//========================================================================================
 lcd.setCursor(0,0);                                          // set cursor 0 colum 0 row
 lcd.print("Distance Measue-");                               // print some text in LCD
 lcd.setCursor(0,1);                                          // set cursor 0 colum 1 row
 lcd.print("ment Using Ultra");                               // print some text in LCD
 delay(3000);                                                 // Delay 3 sec
 lcd.clear();                                                 // LCD Display data'Clear'

 lcd.setCursor(1,0);                                          // set cursor 1 colum 1 row
 lcd.print("Sonic Sensor");                                   // print some text in LCD
 //========================================================================================
                       //Loading Effect
 
 lcd.setCursor(0,1);                                          // set cursor 0 colum 1 row   
 lcd.write(1);                                                // Binary Vector Heart Symbol Print
 delay(400);                                                  // dealay .400 sec
 lcd.setCursor(1,1);                                          // set cursor 1 colum 1 row 
 lcd.write(1);                                                // Binary Vector Heart Symbol Print
 delay(400);                                                  // dealay .400 sec
 lcd.setCursor(2,1);                                          // set cursor 2 colum 1 row                           
 lcd.write(1);                                                // Binary Vector Heart Symbol Print
 delay(400);                                                  // dealay .400 sec
 lcd.setCursor(3,1);                                          // set cursor 3 colum 1 row  
 lcd.write(1);                                                // Binary Vector Heart Symbol Print
 delay(400);                                                  // dealay .400 sec
 lcd.setCursor(4,1);                                          // set cursor 4 colum 1 row  
 lcd.write(1);                                                // Binary Vector Heart Symbol Print
 delay(400);                                                  // dealay .400 sec
 lcd.setCursor(5,1);                                          // set cursor 5 colum 1 row  
 lcd.write(1);                                                // Binary Vector Heart Symbol Print
 delay(400);                                                  // dealay .400 sec
 lcd.setCursor(6,1);                                          // set cursor 6 colum 1 row  
 lcd.write(1);                                                // Binary Vector Heart Symbol Print
 delay(400);                                                  // dealay .400 sec
 lcd.setCursor(7,1);                                          // set cursor 7 colum 1 row  
 lcd.write(1);                                                // Binary Vector Heart Symbol Print
 delay(400);                                                  // dealay .400 sec
 lcd.setCursor(8,1);                                          // set cursor 8 colum 1 row  
 lcd.write(1);                                                // Binary Vector Heart Symbol Print
 delay(400);                                                  // dealay .400 sec
 lcd.setCursor(9,1);                                          // set cursor 9 colum 1 row  
 lcd.write(1);                                                // Binary Vector Heart Symbol Print
 delay(400);                                                  // dealay .400 sec
 lcd.setCursor(10,1);                                         // set cursor 10 colum 1 row  
 lcd.write(1);                                                // Binary Vector Heart Symbol Print
 delay(400);                                                  // dealay .400 sec
 lcd.setCursor(11,1);                                         // set cursor 11 colum 1 row  
 lcd.write(1);                                                // Binary Vector Heart Symbol Print
 delay(400);                                                  // dealay .400 sec
 lcd.setCursor(12,1);                                         // set cursor 12 colum 1 row  
 lcd.write(1);                                                // Binary Vector Heart Symbol Print
 delay(400);                                                  // dealay .400 sec
 lcd.setCursor(13,1);                                         // set cursor 13 colum 1 row  
 lcd.write(1);                                                // Binary Vector Heart Symbol Print
 delay(400);                                                  // dealay .400 sec
 lcd.setCursor(14,1);                                         // set cursor 14 colum 1 row  
 lcd.write(1);                                                // Binary Vector Heart Symbol Print
 delay(400);                                                  // dealay .400 sec
 lcd.setCursor(15,1);                                         // set cursor 15 colum 1 row  
 lcd.write(0);                                                // Binary Vector Arrow Symbol Print
 delay(400);                                                  // dealay .400 sec
 lcd.clear();                                                 // LCD Display data'Clear'
 
}
//========================================================================================
void loop(void) {
                   
HC_SR04();                    // Call The loop funcation
delay(350);                   // Dealay .350 sec
   lcd.clear();               // LCD Display data'Clear'
   lcd.setCursor(3,0);        // set cursor 3 colum 0 row 
   lcd.write(1);              // Binary Vector Heart Symbol Print
   lcd.setCursor(4,0);        // set cursor 3 colum 0 row
   lcd.print("DISTANCE");     // print some text in LCD
   lcd.setCursor(12,0);       // set cursor 12 colum 0 row
   lcd.write(1);              // Binary Vector Heart Symbol Print
   
   
   lcd.setCursor(0,1);        // set cursor 0 colum 1 row
   lcd.print("CM=");          // print some text in LCD
   lcd.setCursor(3,1);        // set cursor 3 colum 1 row
   lcd.print(distanceCM);     // print some text in LCD
   lcd.setCursor(6,1);        // set cursor 6 colum 1 row
   lcd.write(0);              // Binary Vector Arrow Symbol Print
   lcd.setCursor(7,1);        // set cursor 7 colum 1 row
   lcd.print("Inch=");        // print some text in LCD
   lcd.setCursor(12,1);       // set cursor 12 colum 1 row
   lcd.print(distanceInch);   // print some text in LCD


  // Serial.print("Distance:- ");  // serial monitor data Print
  // Serial.print(distanceCM);     // serial monitor data Print
  // Serial.print("CM  ");         // serial monitor data Print
  // Serial.print(distanceInch);   // serial monitor data Print
  // Serial.println("Inch");       // serial monitor data Print
   
   
}
//========================================================================================
                                //Making Custom  loop  Funcation//
 
void HC_SR04(void){
  digitalWrite(trigPin, LOW);           // Ultrasonic TrigPin LOW
  delayMicroseconds(2);                 // Delay 2 Microseconds
  digitalWrite(trigPin, HIGH);          // Ultrasonic TrigPin HIGH
  delayMicroseconds(10);                // Delay 10 Microseconds
  digitalWrite(trigPin, LOW);           // Ultrasonic TrigPin LOW
  duration = pulseIn(echoPin, HIGH);    // dected the plusein (pluse input Pin High)
  
  distanceCM = duration*0.034/2;        // Sound distance  convert into CM

  distanceIn = duration*0.0133;         // Convert into INCH
  distanceInch = distanceIn/2;


}
