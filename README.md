# Year Zero Robotic Arm Project
## Introduction 
This repository is for the Year Zero Robotic Arm project. 

* Included is Arduino sketches and some documentation.

* There are two sketches available to download:
   * YearZeroRobotArmManualInstructions, gives you manaul control over each servo individually and is designed to be used via the command line or the [app]()
   * YearZeroRobotArmMain, is to be used to automate all planned movements you calculated using the latter sketch.

## Installation 

* All you need to do is clone/download (greenButton) and choose download as Zip. 
* Right click an extract at current location (Downloads) or navigate to the ardunio sketch folder on the machine and do it there. 
 > **If you need help ASK!**

## Construction
* [Specification]() - link for specification sheet, please read some useful information inside.

* [Digital Construction Manual](https://www.robotshop.com/media/files/pdf/Braccio_Quick_Start_Guide.pdf)

* Click the image for construction video

  [![](http://img.youtube.com/vi/5VkjJXm6bx8/0.jpg)](https://www.youtube.com/watch?time_continue=16&v=Lwb2ppat_bs "Robotic Arm Construction")

> Make sure you use the right numbered servo motors (numbering on the end of the cable near the connector) in the right joints. And be a bit careful because mounting the servos with the screws causes the plastic to "bloom" a bit and it will never be quite as tight if you have to remove them and put them back in again. Although the plastic pentagons are pre-attached to the servo hub, but I found that some were a few degrees off center, so you just have to adjust your code for that,  **AGAIN IF YOU NEED HELP ASK!**.

* **PLEASE NOTE** that this is only to be used with the Braccio Shield V4 becasue the softstart function protects the servo motors and the junctions from damages
   >* M1 = base degrees. Allowed values from 0 to 180 degrees
   >* M2 = shoulder degrees. Allowed values from 15 to 165 degrees
   >* M3 = elbow degrees. Allowed values from 0 to 180 degrees
   >* M4 = wrist vertical degrees. Allowed values from 0 to 180 degrees
   >* M5 = wrist rotation degrees. Allowed values from 0 to 180 degrees
   >* M6 = gripper degrees. Allowed values from 10 to 73 degrees. 10: the toungue is open, 73: the gripper is closed.

## Health and Safety

* DO NOT put any body part or hair near moving parts and when the robotic arm is in operation 
* DO NOT exceed max load 200g

## Acknowledgements 
* The sketch has been developed to use key functionality from [Braccio Robotic Arm](https://github.com/arduino-org/arduino-library-braccio) so students do not have to download the libraries. 
   * Further modification includes Serial I/O
 > **WARNING** - there has been a request to change some code, [mix-up of wrist values](https://github.com/arduino-org/arduino-library-braccio/pull/4/commits/4ee82eac74b98196bec2413bd87deda3019e3a5c). So please only use the code I have provided in this repository as I have made this change.