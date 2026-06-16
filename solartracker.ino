#include <Servo.h>

Servo trackerServo;
int pos = 90;          // Start position (center 0-180)
int tolerance = 50 ;    // Minimum raw difference to trigger movement
int sensorWait = 15;   

// Pin Definitions
const int ldrLeftPin = A0;
const int ldrRightPin = A1;
const int servoPin = 10; // Changed from 9 to 10

void setup() {
  Serial.begin(9600);
  trackerServo.attach(servoPin); 
  trackerServo.write(pos);      
  
  Serial.println("Solar Tracker Initialized...");
  delay(1000);
}

void loop() {
  // 1. Read raw sensor values
  int leftRaw = analogRead(ldrLeftPin);
  int rightRaw = analogRead(ldrRightPin);

  // 2. Convert raw values to Voltages (0.0V - 5.0V)
  float leftVoltage = leftRaw * (5.0 / 1023.0);
  float rightVoltage = rightRaw * (5.0 / 1023.0);
  
  // 3. Calculate Error Voltage
  float errorVolt = leftVoltage - rightVoltage;

  // 4. Print formatted data
  Serial.print("L_Volt: "); Serial.print(leftVoltage); Serial.print("V");
  Serial.print(" | R_Volt: "); Serial.print(rightVoltage); Serial.print("V");
  Serial.print(" | Error: "); Serial.print(errorVolt); Serial.print("V");
  Serial.print(" | Angle: "); Serial.print(pos); Serial.println(" deg");

  // 5. Movement Logic
  int diff = leftRaw - rightRaw;

  if (abs(diff) > tolerance) {
    if (leftRaw > rightRaw && pos < 180) {
      pos++; 
    } 
    else if (rightRaw > leftRaw && pos > 0) {
      pos--; 
    }
    trackerServo.write(pos); 
  }
  
  delay(sensorWait); 
}