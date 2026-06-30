#include <Joystick.h>

// Initialize the Joystick library with 4 axes and 1 button
Joystick_ Joystick(0x03, JOYSTICK_TYPE_JOYSTICK, 
  1, 0,                  // Button Count: 1, Hat Switch Count: 0
  true, true, true,      // X, Y, and Z axes enabled (A0, A1, A2)
  true, false, false,    // Rx enabled (A3), Ry and Rz disabled
  false, false, false,   // No rudder, throttle, or accelerator flags
  false, false);         // No steering or brake flags

// Define our button pin on digital port 15
const int buttonPin = 15;

void setup() {
  // Configure pin 15 as an input with the internal pull-up resistor
  // This means you do NOT need a wire running to the (+) rail!
  pinMode(buttonPin, INPUT_PULLUP);
  
  // Start the USB Joystick communication
  Joystick.begin();
}

void loop() {
  // 1. Read the analog voltages from ports A0, A1, A2, and A3
  // This reads a value from 0 (0V) to 1023 (5V) based on dial position
  int pot1 = analogRead(A0);
  int pot2 = analogRead(A1);
  int pot3 = analogRead(A2);
  int pot4 = analogRead(A3);

  // 2. Feed those values directly to the Windows Game Controller axes
  Joystick.setXAxis(pot1);
  Joystick.setYAxis(pot2);
  Joystick.setZAxis(pot3);
  Joystick.setRxAxis(pot4);

  // 3. Read the button on port 15
  // Because of INPUT_PULLUP: LOW = pressed (connected to GND), HIGH = released
  int buttonState = digitalRead(buttonPin);
  
  if (buttonState == LOW) {
    Joystick.setButton(0, 1);  // Turn Button 1 ON in Windows
  } else {
    Joystick.setButton(0, 0);  // Turn Button 1 OFF in Windows
  }

  // A tiny 10-millisecond pause to keep things running smoothly
  delay(10);
}
