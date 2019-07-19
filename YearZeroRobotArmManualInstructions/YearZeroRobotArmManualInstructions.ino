/***********************************************************************************************************************
  Sketch amalgamated by: Rich Blair(CompEng0001)
  Date: 09/07/19
  Version: 2.3
  Useage: Year Zero Project Two to control the robotic arm via each servo individually in one sketch
          Input a motor and desired angle into the serial montior and the robotic arm will move. 
          Follow on Serial montior instructions
          This sketch can be used in conjuction with the app in the repository 
  License: GNU Lesser General Public License
  Documentation: https://github.com/CompEng0001/YearZeroRoboticArm
  Acknowledgements: TinkerKit Braccio base libraries -> https://github.com/arduino-org/arduino-library-braccio
***********************************************************************************************************************/

/************************************************************************************************************************************
  DO NOT CHANGE ANYTHING IN THE REGION BELOW (LINES 13 TO 537) OR THE CODE WILL NOT WORK AND WILL CAUSE YOU HOURS/DAYS OF DEBUGGING
 ************************************************************************************************************************************/
// Required library for Servo control
#include <Servo.h>
//The software PWM is connected to PIN 12. You cannot use the pin 12 if you are using
//a Braccio shield V4 or newer
#define SOFT_START_CONTROL_PIN 12
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

int inputNum; // for angle
char c; // for incoming byte from serial

String Command; // for saving c to a string

void setup()
{
  // Open serial for communication
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);

  //initialization of RoboticArm safely
  RoboticArmBegin();
  // Some instructions to screen
  Serial.println("The robot is ready to receive commands when the led is on.");
  Serial.println("When the light is off your command will be processed");
  Serial.println("Remember the robotoic arm will only move when an excepted command is inputted:");
  Serial.println(" * Motor/Servo identifier then desired angle.... eg  Base to 60 degrees = B60");
  Serial.println(" * B = Base, S = Shoulder, E = Elbow, V = wristVertical, R = wristRotation");
  Serial.println("If in doubt refer to documentations or ask for help!");
  delay(1000);
  }

void loop()
{
  //Do not remove this line serialListener() the code will not work.
  serialListener();
}

void serialListener()
{
  // wait for light to show so that you know it is ready to receive commands
  digitalWrite(LED_BUILTIN, HIGH);
  while (Serial.available())
  {
    delay(100);
    c = Serial.read(); // reading the string sent by google voice
    if (c == '#')
    {
      break;
    }
    Command += c;
  }
  if(Command.length() > 2)
  {
    // Turn light off to show that a command is being processed
    digitalWrite(LED_BUILTIN, LOW);
    Command.trim(); //Get rid of any whitespace
    //Serial.println(Command);
    processCommand(); // Action on the String Command to find out which motors to move
  }
}

/**
 * processCommand actions the String Commmand by findings the indentifier and then the angle ie B60
 */
void processCommand()
{
  // Move Elbow
  if (Command.startsWith("E"))
  {
    int newAngle = whichMotor(Command,"E");
    moveElbow(20, newAngle);
    delay(1000);
    Command = "";
  }

  // Move Shoulder
  else if (Command.startsWith("S"))
  {
    int newAngle = whichMotor(Command,"S");
    moveShoulder(20, newAngle);
    delay(1000);
    Command = "";
  }
  
  // Move Base
  else if (Command.startsWith("B"))
  {
    int newAngle = whichMotor(Command,"B");
    moveBase(20, newAngle);
    delay(1000);
    Command = "";
  }

  // Move WritsVer
  else if (Command.startsWith("V"))
  {
    int newAngle = whichMotor(Command,"V");  
    moveWrist_Ver(20, newAngle);
    delay(1000);
    Command = "";
  }

  // Move wristRot
  else if (Command.startsWith("R"))
  {
    int newAngle = whichMotor(Command,"R");
    moveWrist_Rot(20, newAngle);
    delay(1000);
    Command = "";
  }

  // Move Gripper
  else if (Command.startsWith("G"))
  {
    int newAngle = whichMotor(Command,"G");
    moveGripper(20, newAngle);
    delay(1000);
    Command = "";
  }
  // Inform user to enter a legal command
  else
  {
    Serial.println("Please enter a motor letter joined with an angle eg B60: ");
    Command = "";
  }
}

/**
 * Indetifies the right motor to move by searching the String Command and checking against the input motor
 * @param l_Command is the Commmand received from the serail montior
 * @param l_motor is the motor indentifier that must match parent condition.
 * @returnparam angle is the new angle the identified motor will position to.
 */
int whichMotor(String l_Command,String l_Motor)
{
  int lastPos = l_Command.lastIndexOf(l_Motor);
  int lengthCom = l_Command.length();
  String angleString = l_Command.substring(lastPos + 1, lengthCom);
  int angle = angleString.toInt();

  //For Degbugging
  //Serial.print("Angle in string = ");
  //Serial.println(angleString);
  //Serial.print("Angle as int = ");
  //Serial.println(angle);
  return angle;
}

void moveBase(int stepDelay, int vBase)
{
  if (stepDelay > 30)
    stepDelay = 30;
  if (stepDelay < 10)
    stepDelay = 10;
  if (vBase < 0)
    vBase = 0;
  if (vBase > 180)
    vBase = 180;
  int exit = 1;

  // Until the all motors are in the desired position
  while (exit)
  {
    // For each servo motor if next degree is not the same of the previuos than do the movement
    if (vBase != step_base)
    {
      base.write(step_base);
      // One step ahead
      if (vBase > step_base)
      {
        step_base++;
      }
      // One step beyond
      if (vBase < step_base)
      {
        step_base--;
      }
    }
    //delay between each movement
    delay(stepDelay);
    // checks if all the servo motors are in the desired position
    if (vBase == step_base)
    {
      step_base = vBase;
      //Debugging
      Serial.print("Base is: ");
      Serial.println(step_base);
      exit = 0;
    }
    else
    {
      exit = 1;
    }
  }
}

void moveShoulder(int stepDelay, int vShoulder)
{
  if (stepDelay > 30)
    stepDelay = 30;
  if (stepDelay < 10)
    stepDelay = 10;
  if (vShoulder < 15)
    vShoulder = 15;
  if (vShoulder > 165)
    vShoulder = 165;
  int exit = 1;
  // Until the all motors are in the desired position

  while (exit)
  {
    // For each servo motor if next degree is not the same of the previuos than do the movement
    if (vShoulder != step_shoulder)
    {
      shoulder.write(step_shoulder);

      // One step ahead
      if (vShoulder > step_shoulder)
      {
        step_shoulder++;
      }

      // One step beyond
      if (vShoulder < step_shoulder)
      {
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

void moveElbow(int stepDelay, int vElbow)
{
  if (stepDelay > 30)
    stepDelay = 30;
  if (stepDelay < 10)
    stepDelay = 10;
  if (vElbow < 0)
    vElbow = 0;
  if (vElbow > 180)
    vElbow = 180;
  int exit = 1;
  // Until the all motors are in the desired position
  while (exit)
  {
    // For each servo motor if next degree is not the same of the previuos than do the movement
    if (vElbow != step_elbow)
    {
      elbow.write(step_elbow);
      // One step ahead
      if (vElbow > step_elbow)
      {
        step_elbow++;
      }
      // One step beyond
      if (vElbow < step_elbow)
      {
        step_elbow--;
      }
    }
    //delay between each movement
    delay(stepDelay);

    //It checks if all the servo motors are in the desired position
    if (vElbow == step_elbow)
    {
      step_elbow = vElbow;
      //Debugging
      Serial.print("Elbow is: ");
      Serial.println(step_elbow);
      exit = 0;
    }
    else
    {
      exit = 1;
    }
  }
}

void moveWrist_Ver(int stepDelay, int vWrist_Ver)
{
  if (stepDelay > 30)
    stepDelay = 30;
  if (stepDelay < 10)
    stepDelay = 10;
  if (vWrist_Ver < 0)
    vWrist_Ver = 0;
  if (vWrist_Ver > 180)
    vWrist_Ver = 180;
  int exit = 1;

  // Until the all motors are in the desired position
  while (exit)
  {
    // For each servo motor if next degree is not the same of the previuos than do the movement
    if (vWrist_Ver != step_wrist_ver)
    {
      wrist_ver.write(step_wrist_ver);
      // One step ahead
      if (vWrist_Ver > step_wrist_ver)
      {
        step_wrist_ver++;
      }
      // One step beyond
      if (vWrist_Ver < step_wrist_ver)
      {
        step_wrist_ver--;
      }
    }
    //delay between each movement
    delay(stepDelay);
    //It checks if all the servo motors are in the desired position
    if (vWrist_Ver == step_wrist_ver)
    {
      step_wrist_ver = vWrist_Ver;
      //Debugging
      Serial.print("Wrist vertical is: ");
      Serial.println(step_wrist_ver);
      exit = 0;
    }
    else
    {
      exit = 1;
    }
  }
}

void moveWrist_Rot(int stepDelay, int vWrist_rot)
{
  if (stepDelay > 30)
    stepDelay = 30;
  if (stepDelay < 10)
    stepDelay = 10;
  if (vWrist_rot < 0)
    vWrist_rot = 0;
  if (vWrist_rot > 180)
    vWrist_rot = 180;
  int exit = 1;
  // Until the all motors are in the desired position
  while (exit)
  {
    // For each servo motor if next degree is not the same of the previuos than do the movement
    if (vWrist_rot != step_wrist_rot)
    {
      wrist_rot.write(step_wrist_rot);
      // One step ahead
      if (vWrist_rot > step_wrist_rot)
      {
        step_wrist_rot++;
      }
      // One step beyond
      if (vWrist_rot < step_wrist_rot)
      {
        step_wrist_rot--;
      }
    }
    //delay between each movement
    delay(stepDelay);

    //It checks if all the servo motors are in the desired position
    if (vWrist_rot == step_wrist_rot)
    {
      step_wrist_rot = vWrist_rot;
      //Debugging
      Serial.print("Wrist rotation is: ");
      Serial.println(step_wrist_rot);
      exit = 0;
    }
    else
    {
      exit = 1;
    }
  }
}

void moveGripper(int stepDelay, int vgripper)
{
  if (stepDelay > 30)
    stepDelay = 30;
  if (stepDelay < 10)
    stepDelay = 10;
  if (vgripper < 10)
    vgripper = 10;
  if (vgripper > 73)
    vgripper = 73;

  int exit = 1;

  // Until the all motors are in the desired position
  while (exit)
  {
    if (vgripper != step_gripper)
    {
      gripper.write(step_gripper);
      if (vgripper > step_gripper)
      {
        step_gripper++;
      }
      // One step beyond
      if (vgripper < step_gripper)
      {
        step_gripper--;
      }
    }
    //delay between each movement
    delay(stepDelay);
    //It checks if all the servo motors are in the desired position
    if (vgripper == step_gripper)
    {
      step_gripper = vgripper;
      //Debugging
      Serial.print("Gripper is: ");
      Serial.println(step_gripper);
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
  wrist_ver.attach(6);
  wrist_rot.attach(5);
  gripper.attach(3);

  //For each step motor this set up the initial degree
  base.write(90);
  shoulder.write(90);
  elbow.write(180);
  wrist_ver.write(180);
  wrist_rot.write(90);
  gripper.write(10);

  //Previous step motor position
  step_base = 90;
  step_shoulder = 90;
  step_elbow = 180;
  step_wrist_ver = 180;
  step_wrist_rot = 90;
  step_gripper = 10;
  softStart(-35); // delayMicroseconds
}

/**
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

/**
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
/*****************************************************************************************************************************
  END OF REGION
 ****************************************************************************************************************************/