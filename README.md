# Year Zero Robotic Arm Project
## Introduction 
* This repository for the Year Zero Robotic Arm project. 
* Included is Arduino sketch YearZeroRoboticArm.ino and some documentation.
* A sketch has been developed to use key functionality from [Braccio Robotic Arm](https://github.com/arduino-org/arduino-library-braccio) so students do not have to download libraries. 
* Further modification includes Serial I/O

* PLEASE NOTE that this is only to be used with the Braccio Shield V4 becasue the softstart function protects the servo motors and the junctions from damages

## Installation 
* Click the image for construction video

  [![](http://img.youtube.com/vi/5VkjJXm6bx8/0.jpg)](http://www.youtube.com/watch?v=5VkjJXm6bx8 "Robotic Arm Construction")

* [Digital Construction Manaul](https://www.robotshop.com/media/files/pdf/Braccio_Quick_Start_Guide.pdf)

* Make sure you use the right numbered servo motors (numbering on the end of the cable near the connector) in the right joints.  And be a bit careful because mounting the servos with the screws causes the plastic to "bloom" a bit and it will never be quite as tight if you have to remove them and put them back in again.  Although the plastic pentagons are pre-attached to the servo hub, but I found that some were a few degrees off center, so you just have to adjust your code for that.

## Health and Safety

* DO NOT put any body part or hair near moving parts and when the robotic arm is in operation 
* DO NOT exceed max load 200g
