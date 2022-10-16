# on-demand-traffic-light

A traffic lights system with an on-demand crosswalk button. Crosswalk buttons let
the signal operations know that someone is planning to cross the street, so the
light adjusts, giving the pedestrian enough time to get across.
The regular traffic light colors are red, yellow, and green arranged vertically or
horizontally in that order.
Cars' LEDs will be changed every five seconds starting from Green then yellow then
red then yellow then Green.
The Yellow LED will blink for five seconds before moving to Green or Red LEDs.

System components:
1. **ATmega32** microcontroller
2. One push button connected to **INT0** pin for pedestrian with pull up resistor.
3. Three LEDs for cars - Green, Yellow, and Red, connected on port **A**, pins **0**, **1**, and **2**
4. Three LEDs for pedestrians - Green, Yellow, and Red, connected on port **B**, pins **0**, **1**, and **2**

The schematic and simulation is made on **SimuIDE** software.
