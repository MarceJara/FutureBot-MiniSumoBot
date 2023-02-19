---
layout: page
title: Building your robot

#TODOs:
#- Add more explanation in the connections process. 
#- Change the order of the wires to be more clean.
#- Make a walktrought of the building process with photos and a few #sentences.

---

To build our bot we will need the following materials. In some cases we will be able to sustitute some of them but that wil depend on our budget and level of exepertise in order to handle those modifications.

# Electronics

Here, you have the schematic to build the electronic parts of your robot. You can see the connections betwenn ultrasonic sensor, driver, arduino nano, motors and batteries. You can add a switch in the red cable of the batteries.

![SumoBot connections](assets/connections.png){: style="width: 600px;"}

1. Arduino Nano
1. Motor Driver - TB6612FNG
1. Ultrasonic Sensor - HC-SR04
1. DC Motors (Yellow motor) (x2) + Wheels (x2)
1. 4 slots battery case
1. AA Batteries (x4)
1. Switch
1. Jumpers (wires)
1. Protoboard
1. Infrared Sensor - TCRT5000 (in development)

# Mechanics
You will need two wheels that usually come in the same package of your yellow motors. Also, you will need a ball caster. It will work as a support for the front part. Then, all the other parts of the chasis will need to be 3d printed.

1. Wheels (x2) (normally when buying the yellow motors it includes wheels)
1. Caster
1. Chasis 3D printed with PLA+

# 3D printed parts

In the next image, you can see the assembled chasis. Both part 1 and part 2 are variations of the front part so you are free to use whatever you want. Here, we use the 1. front-pale design since i like it over the ramp design. I join parts 1,3,4,5,6 and 7 melting the unions with my soldering iron. I just let part 3. sumo-back-ceiling not melted since you need to be able to take it apart to insert batteries and cables easily.

![SumoBot build](assets/chasis_guide_parts.jpeg){: style="width: 400px;"}

1. [front-pale](https://github.com/MarceJara/FutureBot-MiniSumoBot/blob/gh-pages/assets/3d_models/front_pale.stl)
1. [front-ramp](https://github.com/MarceJara/FutureBot-MiniSumoBot/blob/gh-pages/assets/3d_models/front_ramp.stl)
1. [sumo-back-ceiling](https://github.com/MarceJara/FutureBot-MiniSumoBot/blob/gh-pages/assets/3d_models/sumo_back_ceiling.stl)
1. [sumo-base](https://github.com/MarceJara/FutureBot-MiniSumoBot/blob/gh-pages/assets/3d_models/sumo_base.stl)
1. [sumo-front-ceiling](https://github.com/MarceJara/FutureBot-MiniSumoBot/blob/gh-pages/assets/3d_models/sumo_front_ceiling.stl)
1. [sumo-side-left](https://github.com/MarceJara/FutureBot-MiniSumoBot/blob/gh-pages/assets/3d_models/sumo_side_left.stl)
1. [sumo-side-right](https://github.com/MarceJara/FutureBot-MiniSumoBot/blob/gh-pages/assets/3d_models/sumo_side_right.stl)
1. [ultrasonic-support](https://github.com/MarceJara/FutureBot-MiniSumoBot/blob/gh-pages/assets/3d_models/ultrasonic_support.stl)

Motors and ultrasound sensor are pretty much standard in size. When you will find issues is in the switch size. If you now a bit of OpenSCAD you can actually download the following file which is the design file of part 3. sumo-back-ceiling. Then, you will be able to modify the width and heigth given the switch you have bought. 

- [sumo-back-ceiling-editable](https://github.com/MarceJara/FutureBot-MiniSumoBot/blob/gh-pages/assets/3d_models/sumo-back-ceiling-editable.scad)

TODOs:
- Explain the building process step by step.
- Make a recommendations part.

