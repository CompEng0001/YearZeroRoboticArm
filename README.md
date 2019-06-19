# Year Zero Robotic Arm Project
## Introduction 
This repository is for the Year Zero Robotic Arm project. 

* Included is Arduino sketches and some documentation.

* The sketch has been developed to use key functionality from [Braccio Robotic Arm](https://github.com/arduino-org/arduino-library-braccio) so students do not have to download the libraries. 

* Further modification includes Serial I/O

* PLEASE NOTE that this is only to be used with the Braccio Shield V4 becasue the softstart function protects the servo motors and the junctions from damages

* There are 6 sketches that are available to use to control individual servos and a 7th sketchs(YearZeroRobotArmMain) that controls all servos via one function. 

## Installation 

* All you need to do is clone/download (greenButton) and choose download as Zip. 
* Right click an extract at current location or navigate to the ardunio sketch folder on the machine and do it there. 

## Consturction
* [Specification]() - link for specification sheet, please read some useful information inside.

* Click the image for construction video

  [![](http://img.youtube.com/vi/5VkjJXm6bx8/0.jpg)](https://www.youtube.com/watch?time_continue=16&v=Lwb2ppat_bs "Robotic Arm Construction")

* [Digital Construction Manaul](https://www.robotshop.com/media/files/pdf/Braccio_Quick_Start_Guide.pdf)

>Make sure you use the right numbered servo motors (numbering on the end of the cable near the connector) in the right joints.  And be a bit careful because mounting the servos with the screws causes the plastic to "bloom" a bit and it will never be quite as tight if you have to remove them and put them back in again.  Although the plastic pentagons are pre-attached to the servo hub, but I found that some were a few degrees off center, so you just have to adjust your code for that.

## Health and Safety

* DO NOT put any body part or hair near moving parts and when the robotic arm is in operation 
* DO NOT exceed max load 200g
