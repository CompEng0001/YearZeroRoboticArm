/* Sketch amalgamated by: Richard Blair
   Date: 14/06/19
   Version: 1.0.3
   Useage: Year Zero Project Two to control the Shoulder only
   License: GNU Lesser General Public License
   Acknowledgements: TinkerKit Braccio base libraries -> https://github.com/arduino-org/arduino-library-braccio
*/

/*******************************************************************************************************************
   DO NOT CHANGE ANYTHING IN THE SECTION BELOW OR THE CODE WILL NOT WORK AND WILL CAUSE YOU HOURS/DAYS OF DEBUGGING
 *******************************************************************************************************************/

// Required library for Servo control
#include <Servo.h>

//The software PWM is connected to PIN 12. You cannot use the pin 12 if you are using
//a Braccio shield V4 or newer
#define SOFT_START_CONTROL_PIN	12

//Low and High Limit Timeout for the Software PWM
#define LOW_LIMIT_TIMEOUT 2000
#define HIGH_LIMIT_TIMEOUT 6000

// setup of Servo objects *note* names to represent position of servo on robotic arm
Servo base;
Servo shoulder;
Servo elbow;
Servo wrist_rot;
Servo wrist_ver;
Servo gripper;

// set up angles for each servo object
int step_base, step_shoulder, step_elbow, step_wrist_ver, step_wrist_rot, step_gripper;
int inputNum;
char c;
String Command;

void setup()
{
  // Open serial for communication
  Serial.begin(115200);

  //initialization of RoboticArm safely
  RoboticArmBegin();
}
/*****************************************************************************************************************
  END OF SECTION, YOU CAN ADD YOUR OWN VARIABLES 
 *****************************************************************************************************************/

void loop()
{
  while (Serial.available())
  {
    delay(10);
    c = Serial.read();// reading the string sent by google voice
    if (c == '#')
    {
      break;
      delay(10);
    }

    Command += c;

    inputNum = Command.toInt();
  }
  
   //SD = a milliseconds delay between the movement of each servo.  Allowed values from 10 to 30 msec.
   //SH = shoulder degrees. Allowed values from 15 to 165 degrees
            //(SD,   SH)
   moveShoulder(20, inputNum);

   delay(1000);
   
   Command = "";
}

/*****************************************************************************************************************************
  DO NOT CHANGE ANYTHING BELOW OR RISK DAMAGING THE ROBOTIC ARM
 ****************************************************************************************************************************/
void moveShoulder(int stepDelay, int vShoulder)
{
  if (stepDelay > 30) stepDelay = 30;
  if (stepDelay < 10) stepDelay = 10;
  if (vShoulder < 15) vShoulder = 15;
  if (vShoulder > 165) vShoulder = 165;
  int exit = 1;

  // Until the all motors are in the desired position
 while (exit)
 {
    // For each servo motor if next degree is not the same of the previuos than do the movement
   if (vShoulder != step_shoulder)
    {
      shoulder.write(step_shoulder);
      // One step ahead
      if (vShoulder > step_shoulder) {
        step_shoulder++;
      }
      // One step beyond
      if (vShoulder < step_shoulder) {
        step_shoulder--;
      }
    }
  
    //delay between each movement
    delay(stepDelay);

    //It checks if all the servo motors are in the desired position
   if (vShoulder == step_shoulder)
    {
      step_shoulder = vShoulder;
      //Debugging
      Serial.print("Shoulder is: ");
      Serial.println(step_shoulder);
      exit = 0;
    }
   else
    {
      exit = 1;
    }
 }

}

/**
   Braccio initialization and set intial position
   Modifing this function you can set up the initial position of all the
   servo motors of Braccio
   @param soft_start_level: default value is 0 (SOFT_START_DEFAULT)
   You should set begin(SOFT_START_DISABLED) if you are using the Arm Robot shield V1.6
   SOFT_START_DISABLED disable the Braccio movements
*/
void RoboticArmBegin()
{
  //Calling Braccio.begin(SOFT_START_DISABLED) the Softstart is disabled and you can use the pin 12
  pinMode(SOFT_START_CONTROL_PIN, OUTPUT);
  digitalWrite(SOFT_START_CONTROL_PIN, LOW);

  // initialization pin Servo motors
  base.attach(11);
  shoulder.attach(10);
  elbow.attach(9);
  wrist_rot.attach(6);
  wrist_ver.attach(5);
  gripper.attach(3);

  //For each step motor this set up the initial degree
  base.write(0);
  shoulder.write(40);
  elbow.write(180);
  wrist_ver.write(170);
  wrist_rot.write(0);
  gripper.write(73);

  //Previous step motor position
  step_base = 0;
  step_shoulder = 40;
  step_elbow = 180;
  step_wrist_ver = 170;
  step_wrist_rot = 0;
  step_gripper = 73;

  softStart(-35); // delayMicroseconds
}

/*
    This function, used only with the Braccio Shield V4 and greater,
    turn ON the Braccio softly and save Braccio from brokes.
    The SOFT_START_CONTROL_PIN is used as a software PWM
    @param soft_start_level: the minimum value is -70, , default value is 0 (SOFT_START_DEFAULT)
*/
void softStart(int soft_start_level)
{
  long int tmp = millis();
  while (millis() - tmp < LOW_LIMIT_TIMEOUT)
    softwarePWM(80 + soft_start_level, 450 - soft_start_level); //the sum should be 530usec

  while (millis() - tmp < HIGH_LIMIT_TIMEOUT)
    softwarePWM(75 + soft_start_level, 430 - soft_start_level); //the sum should be 505usec

  digitalWrite(SOFT_START_CONTROL_PIN, HIGH);
}

/*
   Software implementation of the PWM for the SOFT_START_CONTROL_PIN,HIGH
   @param high_time: the time in the logic level high
   @param low_time: the time in the logic level low
*/
void softwarePWM(int high_time, int low_time)
{
  digitalWrite(SOFT_START_CONTROL_PIN, HIGH);
  delayMicroseconds(high_time);
  digitalWrite(SOFT_START_CONTROL_PIN, LOW);
  delayMicroseconds(low_time);
}
