#include <Ps3Controller.h>

// Right motor
int enableRightMotor = 22; 
int rightMotorPin1 = 16;
int rightMotorPin2 = 17;
// Left motor
int enableLeftMotor = 23;
int leftMotorPin1 = 18;
int leftMotorPin2 = 19;

#define MAX_MOTOR_SPEED 200

// Seeding and Watering Motor Pins (L298N Motor Driver)
int seedingMotorPin1 = 15;
int seedingMotorPin2 = 5;
int wateringMotorPin1 = 2;
int wateringMotorPin2 = 21;

const int PWMFreq = 1000; /* 1 KHz */
const int PWMResolution = 8;
const int PWMSpeedChannel = 4;

void notify()
{
  int yAxisValue = (Ps3.data.analog.stick.ly);  // Left stick - y axis - forward/backward car movement
  int xAxisValue = (Ps3.data.analog.stick.rx);  // Right stick - x axis - left/right car movement

  if (yAxisValue <= -50)       // Move car Forward
  {
    rotateMotor(MAX_MOTOR_SPEED, MAX_MOTOR_SPEED);
    digitalWrite(26, HIGH);
    digitalWrite(27, HIGH);
  }
  else if (yAxisValue >= 50)   // Move car Backward
  {
    rotateMotor(-MAX_MOTOR_SPEED, -MAX_MOTOR_SPEED);
  }
  else if (xAxisValue >= 50)  // Move car Right
  {
    rotateMotor(-MAX_MOTOR_SPEED, MAX_MOTOR_SPEED);
    digitalWrite(32, HIGH);
    digitalWrite(27, HIGH);
  }
  else if (xAxisValue <= -50)   // Move car Left
  {
    rotateMotor(MAX_MOTOR_SPEED, -MAX_MOTOR_SPEED);
    digitalWrite(33, HIGH);
    digitalWrite(26, HIGH);
  }
  else if (Ps3.event.button_down.triangle)       // Move car slow
  {
    rotateMotor(50, 50);
  }
  else                                      // Stop the car
  {
    rotateMotor(0, 0);
    digitalWrite(26, LOW);
    digitalWrite(27, LOW);
    digitalWrite(32, LOW);
    digitalWrite(33, LOW);
  }

  // Seeding control
  if (Ps3.event.button_down.cross)   // Start seeding
  {
    Serial.println("Seeding started.");
    digitalWrite(seedingMotorPin1, HIGH);
    digitalWrite(seedingMotorPin2, LOW); // Forward direction
    delay(100);  // Small delay for observability
  }
  if (Ps3.event.button_up.cross)     // Stop seeding
  {     
    Serial.println("Seeding stopped.");
    digitalWrite(seedingMotorPin1, LOW);
    digitalWrite(seedingMotorPin2, LOW);
  } 

  // Watering control
  if (Ps3.event.button_down.square)   // Start watering
  {
    Serial.println("Watering started.");
    digitalWrite(wateringMotorPin1, HIGH);
    digitalWrite(wateringMotorPin2, LOW); // Forward direction
    delay(100);  // Small delay for observability
  }
  if (Ps3.event.button_up.square)     // Stop watering
  {        
    Serial.println("Watering stopped.");
    digitalWrite(wateringMotorPin1, LOW);
    digitalWrite(wateringMotorPin2, LOW);
  } 
}

void onConnect()
{
  Serial.println("Connected!.");
  Ps3.setPlayer(1);
}

void onDisConnect()
{
  rotateMotor(0, 0);
}

void rotateMotor(int rightMotorSpeed, int leftMotorSpeed)
{
  if (rightMotorSpeed < 0)
  {
    digitalWrite(rightMotorPin1, LOW);
    digitalWrite(rightMotorPin2, HIGH);    
  }
  else if (rightMotorSpeed > 0)
  {
    digitalWrite(rightMotorPin1, HIGH);
    digitalWrite(rightMotorPin2, LOW);      
  }
  else
  {
    digitalWrite(rightMotorPin1, LOW);
    digitalWrite(rightMotorPin2, LOW);      
  }
  
  if (leftMotorSpeed < 0)
  {
    digitalWrite(leftMotorPin1, LOW);
    digitalWrite(leftMotorPin2, HIGH);    
  }
  else if (leftMotorSpeed > 0)
  {
    digitalWrite(leftMotorPin1, HIGH);
    digitalWrite(leftMotorPin2, LOW);      
  }
  else
  {
    digitalWrite(leftMotorPin1, LOW);
    digitalWrite(leftMotorPin2, LOW);      
  }  
}

void setUpPinModes()
{
  pinMode(enableRightMotor, OUTPUT);
  pinMode(rightMotorPin1, OUTPUT);
  pinMode(rightMotorPin2, OUTPUT);
  
  pinMode(enableLeftMotor, OUTPUT);
  pinMode(leftMotorPin1, OUTPUT);
  pinMode(leftMotorPin2, OUTPUT);

  // Set up PWM for motor speed
  ledcSetup(PWMSpeedChannel, PWMFreq, PWMResolution);
  ledcAttachPin(enableRightMotor, PWMSpeedChannel);
  ledcAttachPin(enableLeftMotor, PWMSpeedChannel);  
  ledcWrite(PWMSpeedChannel, MAX_MOTOR_SPEED);
  
  // Set up Seeding and Watering Motor pins
  pinMode(seedingMotorPin1, OUTPUT);
  pinMode(seedingMotorPin2, OUTPUT);
  pinMode(wateringMotorPin1, OUTPUT);
  pinMode(wateringMotorPin2, OUTPUT);
  
  rotateMotor(0, 0);
}

void setup()
{
  pinMode(26, OUTPUT);
  pinMode(27, OUTPUT);
  pinMode(32, OUTPUT);
  pinMode(33, OUTPUT);
  setUpPinModes();
  Serial.begin(115200);
  Ps3.attach(notify);
  Ps3.attachOnConnect(onConnect);
  Ps3.attachOnDisconnect(onDisConnect);
  Ps3.begin();
  Serial.println("Ready.");
}

void loop()
{
}
