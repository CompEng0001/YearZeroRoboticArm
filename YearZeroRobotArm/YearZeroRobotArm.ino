/* Sketch amalgamated by: Richard Blair
 * Date: 14/06/19
 * Version: 1.0.5
 * Useage: Year Zero Project Two 
 * License: GNU Lesser General Public License
 * Acknowledgements: TinkerKit Braccio base libraries -> https://github.com/arduino-org/arduino-library-braccio
 */

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
int step_base, step_shoulder, step_elbow, step_wrist_ver, step_wrist_rot,  step_gripper;

void setup() 
{
  // Open serial for communication
  Serial.begin(115200);

  //initialization of RoboticArm safely 
  RoboticArmBegin();
}

void loop() 
{
  /*
    SD = a milliseconds delay between the movement of each servo.  Allowed values from 10 to 30 msec.
    BA = base degrees. Allowed values from 0 to 180 degrees
    SH = shoulder degrees. Allowed values from 15 to 165 degrees
    EL = elbow degrees. Allowed values from 0 to 180 degrees
    WV = wrist vertical degrees. Allowed values from 0 to 180 degrees
    WR = wrist rotation degrees. Allowed values from 0 to 180 degrees
    GR = gripper degrees. Allowed values from 10 to 73 degrees. 10: the toungue is open, 73: the gripper is closed.
  */
                    //(SD, BA, SH,  EL,  WV,  WR,  GR);
    RoboticArmMovement(20,  0, 15, 180, 170,   0,  73);  
    //Wait 1 second
    delay(1000);

                    //(SD,  BA,  SH,  EL,  WV,   WR,  GR);
    RoboticArmMovement(20, 180, 165,   0,   0,  180,  10);  
    //Wait 1 second
    delay(1000);

	//return Robotic Arm to saftey position.
	RoboticArmSafteyPosition();  
	//Wait 1 second
	delay(1000);
}


/*****************************************************************************************************************************
 DO NOT CHANGE ANYTHING BELOW OR RISK DAMAGING THE ROBOTIC ARM
 *****************************************************************************************************************************/

/**
 * Braccio initialization and set intial position
 * Modifing this function you can set up the initial position of all the
 * servo motors of Braccio
 * @param soft_start_level: default value is 0 (SOFT_START_DEFAULT)
 * You should set begin(SOFT_START_DISABLED) if you are using the Arm Robot shield V1.6
 * SOFT_START_DISABLED disable the Braccio movements
 */
void RoboticArmBegin() 
{
    //Calling Braccio.begin(SOFT_START_DISABLED) the Softstart is disabled and you can use the pin 12
	pinMode(SOFT_START_CONTROL_PIN,OUTPUT);
	digitalWrite(SOFT_START_CONTROL_PIN,LOW);
 
    // initialization pin Servo motors
	base.attach(11);
	shoulder.attach(10);
	elbow.attach(9);
	wrist_rot.attach(6);
	wrist_ver.attach(5);
	gripper.attach(3);
        
	//All servos will be positioned in the "safety" position
	base.write(90);
	shoulder.write(45);
	elbow.write(180);
	wrist_ver.write(180);
	wrist_rot.write(90);
	gripper.write(10);
  
	//Previous step motor position
	step_base = 90;
	step_shoulder = 45;
	step_elbow = 180;
	step_wrist_ver = 180;
	step_wrist_rot = 90;
	step_gripper = 10;

    softStart(-35); // delayMicroseconds
}

/**
 * This functions allow you to control all the servo motors
 * 
 * @param stepDelay The delay between each servo movement
 * @param vBase next base servo motor degree
 * @param vShoulder next shoulder servo motor degree
 * @param vElbow next elbow servo motor degree
 * @param vWrist_ver next wrist rotation servo motor degree
 * @param vWrist_rot next wrist vertical servo motor degree
 * @param vgripper next gripper servo motor degree
 */
void RoboticArmMovement(int stepDelay, int vBase, int vShoulder, int vElbow,int vWrist_ver, int vWrist_rot, int vgripper) 
{
	// DO NOT CHANGE VALUES, this avoids dangerous positions for the Braccio  
    if (stepDelay > 30) stepDelay = 30;
	if (stepDelay < 10) stepDelay = 10;
	if (vBase < 0) vBase=0;
	if (vBase > 180) vBase=180;
	if (vShoulder < 15) vShoulder=15;
	if (vShoulder > 165) vShoulder=165;
	if (vElbow < 0) vElbow=0;
	if (vElbow > 180) vElbow=180;
	if (vWrist_ver < 0) vWrist_ver=0;
	if (vWrist_ver > 180) vWrist_ver=180;
	if (vWrist_rot > 180) vWrist_rot=180;
	if (vWrist_rot < 0) vWrist_rot=0;
    if (vgripper < 10) vgripper = 10;
	if (vgripper > 73) vgripper = 73;

	int exit = 1;

	// Until the all motors are in the desired position
	while (exit) 
	{			
		// For each servo motor if next degree is not the same of the previuos than do the movement		
		if (vBase != step_base) 
		{			
			base.write(step_base);
			// One step ahead
			if (vBase > step_base) {
				step_base++;
			}
			// One step beyond
			if (vBase < step_base) {
				step_base--;
			}
		}

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

		if (vElbow != step_elbow)  
		{
			elbow.write(step_elbow);
			// One step ahead
			if (vElbow > step_elbow) {
				step_elbow++;
			}
			// One step beyond
			if (vElbow < step_elbow) {
				step_elbow--;
			}
		}

		if (vWrist_ver != step_wrist_rot) 
		{
			wrist_rot.write(step_wrist_rot);
			// One step ahead
			if (vWrist_ver > step_wrist_rot) {
				step_wrist_rot++;				
			}
			// One step beyond
			if (vWrist_ver < step_wrist_rot) {
				step_wrist_rot--;
			}
		}

		if (vWrist_rot != step_wrist_ver)
		{
			wrist_ver.write(step_wrist_ver);
			// One step ahead
			if (vWrist_rot > step_wrist_ver) {
				step_wrist_ver++;
			}
			// One step beyond
			if (vWrist_rot < step_wrist_ver) {
				step_wrist_ver--;
			}
		}

		if (vgripper != step_gripper)
		{
			gripper.write(step_gripper);
			if (vgripper > step_gripper) {
				step_gripper++;
			}
			// One step beyond
			if (vgripper < step_gripper) {
				step_gripper--;
			}
		}
		
		//delay between each movement
		delay(stepDelay);
		
		//It checks if all the servo motors are in the desired position 
		if ((vBase == step_base) && (vShoulder == step_shoulder)
				&& (vElbow == step_elbow) && (vWrist_ver == step_wrist_rot)
				&& (vWrist_rot == step_wrist_ver) && (vgripper == step_gripper)) 
      	{
			step_base = vBase;
			step_shoulder = vShoulder;
			step_elbow = vElbow;
			step_wrist_rot = vWrist_ver;
			step_wrist_ver = vWrist_rot;
			step_gripper = vgripper;

			//Debugging 
			Serial.print("Base is: ");
			Serial.println(step_base);
			Serial.print("Shoulder is: ");
			Serial.println(step_shoulder);
			Serial.print("Elbow is: ");
			Serial.println(step_elbow);
			Serial.print("Wrist Verticle is: ");
			Serial.println(step_wrist_ver);
			Serial.print("Wrist Rotation is: ");
			Serial.println(step_wrist_rot);
			Serial.print("Gripper is: ");
			Serial.println(step_gripper);

			exit = 0;
		} 
    else 
    {      
		exit = 1;
	}
}

/**
 * Use this function to return to saftey position. 
*/
void RoboticArmSafteyPosition()
{
	//All servos will be positioned in the "safety" position
	base.write(90);
	shoulder.write(45);
	elbow.write(180);
	wrist_ver.write(180);
	wrist_rot.write(90);
	gripper.write(10);
  
	//Previous step motor position
	step_base = 90;
	step_shoulder = 45;
	step_elbow = 180;
	step_wrist_ver = 180;
	step_wrist_rot = 90;
	step_gripper = 10;	

	softStart(-35); // delayMicroseconds
}

/*
  * This function, used only with the Braccio Shield V4 and greater,
  * turn ON the Braccio softly and save Braccio from brokes.
  * The SOFT_START_CONTROL_PIN is used as a software PWM
  * @param soft_start_level: the minimum value is -70, , default value is 0 (SOFT_START_DEFAULT)
  */
void softStart(int soft_start_level)
{      
	long int tmp=millis();
	while(millis()-tmp < LOW_LIMIT_TIMEOUT)
		softwarePWM(80+soft_start_level, 450 - soft_start_level);   //the sum should be 530usec	

	while(millis()-tmp < HIGH_LIMIT_TIMEOUT)
		softwarePWM(75 + soft_start_level, 430 - soft_start_level); //the sum should be 505usec

	digitalWrite(SOFT_START_CONTROL_PIN,HIGH);
}

/*
  * Software implementation of the PWM for the SOFT_START_CONTROL_PIN,HIGH
  * @param high_time: the time in the logic level high
  * @param low_time: the time in the logic level low
  */
void softwarePWM(int high_time, int low_time)
{
	digitalWrite(SOFT_START_CONTROL_PIN,HIGH);
	delayMicroseconds(high_time);
	digitalWrite(SOFT_START_CONTROL_PIN,LOW);
	delayMicroseconds(low_time); 
}
