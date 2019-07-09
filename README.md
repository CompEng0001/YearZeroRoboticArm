# Year Zero Robotic Arm Project
## Introduction

This repository is for the Year Zero Robotic Arm project, included is Arduino sketches, software and some documentation.

**Sketches**
   * [YearZeroRobotArmManualInstructions](https://github.com/CompEng0001/YearZeroRoboticArm/tree/master/YearZeroRobotArmManualInstructions), gives you manaul control over each servo individually and is designed to be used via the command line or the [Robotic Arm app](https://github.com/CompEng0001/YearZeroRoboticArm/tree/master/App)
   * [YearZeroRobotArmMain](https://github.com/CompEng0001/YearZeroRoboticArm/tree/master/YearZeroRobotArmMain), is to be used to automate all planned movements you calculated using the latter sketch.

**App**
   * The [RoboticArm app](https://github.com/CompEng0001/YearZeroRoboticArm/tree/master/App) has been downloaded on to the Android OS tablets supplied with this robotic arm, please note it is developed for Android only.
     The App is available for you to download on your own device, but as this is open source you install it **at your own risk**, as you should only install from trustworthy sources.
   * Four Screen shots have been included with the [RoboticArm app](https://github.com/CompEng0001/YearZeroRoboticArm/tree/master/App) folder.
   * Code is available to view as an image in the same folder as the [RoboticArm app](https://github.com/CompEng0001/YearZeroRoboticArm/tree/master/App)

**Specification** 
   * [Specification](https://github.com/CompEng0001/YearZeroRoboticArm/blob/master/Specifications.md) - link for specification sheet, please read some useful information inside.

## Installation 

* All you need to do is clone/download (greenButton) and choose download as Zip. 
* Right click an extract at current location (Downloads) or navigate to the ardunio sketch folder on the machine and do it there. 
**If you need help ASK!**

## Construction

* [Digital Construction Manual](https://www.robotshop.com/media/files/pdf/Braccio_Quick_Start_Guide.pdf)

**Click the image to be redirected to the construction video on you tube**

  [![](http://img.youtube.com/vi/5VkjJXm6bx8/0.jpg)](https://www.youtube.com/watch?time_continue=16&v=Lwb2ppat_bs "Robotic Arm Construction")

> Make sure you use the right numbered servo motors (numbering on the end of the cable near the connector) in the right joints. And be a bit careful because mounting the servos with the screws causes the plastic to "bloom" a bit and it will never be quite as tight if you have to remove them and put them back in again. Although the plastic pentagons are pre-attached to the servo hub, but I found that some were a few degrees off center, so you just have to adjust your code for that,  **AGAIN IF YOU NEED HELP ASK!**.

## Acknowledgements 

* The sketch has been developed to use key functionality from [Braccio Robotic Arm](https://github.com/arduino-org/arduino-library-braccio) so students do not have to download the libraries. 
   * Further modification includes Serial I/O
**PLEASE NOTE** that this is only to be used with the Braccio Shield V4 becasue the softstart function protects the servo motors and the junctions from damages

**WARNING** 
There has been a request to change some code in the original source code linked above, [mix-up of wrist values](https://github.com/arduino-org/arduino-library-braccio/pull/4/commits/4ee82eac74b98196bec2413bd87deda3019e3a5c). So please only use the code that is provided in this repository as the change has been incorporated.

## Health and Safety

* DO NOT put any body parts or hair near moving parts and when the robotic arm is in operation 
* DO NOT exceed max load 200g