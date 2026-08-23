#include <SoftwareSerial.h>

#define BT_RX 0
#define BT_TX 1

SoftwareSerial BTSerial(BT_RX, BT_TX);

// Motor control pins
int enA = 9;  // Enable pin for Motor A (PWM)
int enB = 3;  // Enable pin for Motor B (PWM)
int in1 = 8;  // Motor A input 1
int in2 = 7;  // Motor A input 2
int in3 = 5;  // Motor B input 1
int in4 = 4;  // Motor B input 2

char command; // Variable to store received command

void setup() {
  Serial.begin(9600);       // Initialize serial communication for debugging
  BTSerial.begin(9600);     // Initialize Bluetooth serial communication
  pinMode(enA, OUTPUT);     // Set motor control pins as output
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

void loop() {
  // Set motor speed using PWM
  analogWrite(enA, 70); // Adjust PWM value as needed
  analogWrite(enB, 70); // Adjust PWM value as needed

  // Check for command from Bluetooth
  if (BTSerial.available()) {
    command = BTSerial.read();
    executeCommand(command);
  }

  // Check for command from Serial
  if (Serial.available()) {
    command = Serial.read();
    executeCommand(command);
  }
}

void executeCommand(char cmd) {
  switch (cmd) {
    case 'A': // Forward
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
      break;
    case 'B': // Backward
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
      break;
    case 'D': // Left
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
      break;
    case 'C': // Right
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
      break;
    case 'S': // Stop
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in4, LOW);
      break;
    default:
      Serial.println("Unknown command received from Bluetooth or Serial");
      break;
  }
}
