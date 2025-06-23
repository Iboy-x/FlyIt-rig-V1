// Requires Arduino Joystick Library https://github.com/MHeironimus/ArduinoJoystickLibrary
#include <Joystick.h>
Joystick_ Joystick;
 
int JoystickX;
int JoystickY;
int JoystickZ;
int Throttle;
int Rudder;
int Aux1;
int Aux2;
int currentButtonState0;
int lastButtonState0;
int currentButtonState1;
int lastButtonState1;
int currentButtonState2;
int lastButtonState2;
int currentButtonState3;
int lastButtonState3;
int currentButtonState4;
int lastButtonState4;
int currentButtonState5;
int lastButtonState5;
int currentButtonState6;
int lastButtonState6;

void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
// Initialize Joystick Library
  Joystick.begin();
  Joystick.setXAxisRange(0, 965); 
  Joystick.setYAxisRange(192, 522);
  Joystick.setZAxisRange(143, 735);
  Joystick.setRxAxisRange(158, 456);
  Joystick.setRyAxisRange(158, 456);
  Joystick.setThrottleRange(154, 448);
}

void loop() {

// Read Joystick
  JoystickX = analogRead(A0);
  JoystickY = analogRead(A1);
  JoystickZ=analogRead(A8);
  Throttle=analogRead(A2);
  Aux1=analogRead(A9);
  Aux2=analogRead(A3);
  Serial.print(JoystickX);
  Serial.print("   ");
  Serial.print(JoystickY);
  Serial.print("   ");
  Serial.println(JoystickZ);


// Read Switches
int currentButtonState0 = !digitalRead(2); // Button 0
  if (currentButtonState0 != lastButtonState0)
  {
  Joystick.setButton(0, currentButtonState0);
  lastButtonState0 = currentButtonState0;
  }

int currentButtonState1 = !digitalRead(3); // Button 1
  if (currentButtonState1 != lastButtonState1)
  {
  Joystick.setButton(1, currentButtonState1);
  lastButtonState1 = currentButtonState1;
  }
  
int currentButtonState2 = !digitalRead(4); // Button 2
  if (currentButtonState2 != lastButtonState2)
  {
  Joystick.setButton(2, currentButtonState2);
  lastButtonState2 = currentButtonState2;
  }

int currentButtonState3 = !digitalRead(5); // Button 3
  if (currentButtonState3 != lastButtonState3)
  {
  Joystick.setButton(3, currentButtonState3);
  lastButtonState3 = currentButtonState3;
  }
  
int currentButtonState4 = !digitalRead(6); // Button 4
  if (currentButtonState4 != lastButtonState4)
  {
  Joystick.setButton(4, currentButtonState4);
  lastButtonState4 = currentButtonState4;
  } 

int currentButtonState5 = !digitalRead(7); // Button 5
  if (currentButtonState5 != lastButtonState5)
  {
  Joystick.setButton(5, currentButtonState5);
  lastButtonState5 = currentButtonState5;
  } 
  
   
// Output Controls
  Joystick.setXAxis(JoystickX);
  Joystick.setYAxis(JoystickY);
  Joystick.setZAxis(JoystickZ);
  Joystick.setThrottle(Throttle);
  Joystick.setRxAxis(Aux1);
  Joystick.setRyAxis(Aux2);
  Joystick.sendState();

} 
