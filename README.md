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


## Specifications 

### Physical Characteristics

* Plastic Parts x 21
* Screws x 63
* Flat Washer x 16
* Hexagon Nut x 7
* Springs x 2
* Servo Motors: 2 x SR 311, 4 x SR 431
* Arduino compatible Shield x 1
* Power Supply 5V, 5A x 1
* Phillips Screwdriver x 1
* Double Hexagon Box Wrench x 1
* Spiral Cable Protection Wrap x 1

### Fully assembled Braccio Kit:

* Weight: 792 g
* Maximum operating distance range: 80 cm
* Maximum Height : 52 cm
* Base Width: 14 cm
* Gripper Width: 90 mm
* Cable length: 40 cm
* Load Capacity: Maximum weight at 32 cm operating distance: 150 g, Maximum weight at the minimal Braccio configuration: 400g

### Servo Technical Specification

#### SpringRC SR431 - Dual Output Servo:

* Control Signal: PWM Analog
* Torque: @ 4.8V: 169.5 oz-in (12.2 kg-cm), @ 6.0V: 201.4 oz-in (14.5 kg-cm)
* Weight: 2.19 oz (62.0 g)
* Dimentions: 1.65×0.81×1.56 in (42.0×20.5×39.5 mm)
* Speed: @ 4.8V: 0.20 sec/60°, @ 6.0V: 0.18 sec/60°
* Rotation Support: Dual Bearings
* Gear Material: Metal
* Rotation Range: 180°
* Connector Type: J (aka Futaba)

#### SpringRC SR311:

* Control Signal: PWM Analog
* Torque: @ 4.8V: 43.13 oz-in (3.1 kg-cm), @ 6.0V: 52.86 oz-in (3.8 kg-cm)
* Weight: 0.95 oz (27.0 g)
* Dimentions: 1.23×0.65×1.13 in (31.3×16.5×28.6 mm)
* Speed: @ 4.8V: 0.14 sec/60°, @ 6.0V: 0.12 sec/60°
* Rotation Support: Dual Bearings
* Gear Material: Metal
* Rotation Range: 180°
* Connector Type: J (aka Futaba)