# Leap-Wheels

![alt tag](http://i.imgur.com/ajAa2Ic.jpg)

Leap motion controlled minicar equipped with 4 stepper motors and an Intel Edison. Built at DragonHacks Jan 2015.
Downloaded Leap motion SDK on Mac and opened visualizer to see hands moving.
Began to use leap motion API in python wrappers to manipulate leap motion data.

Car was built from scratch, wheel bearings were 3D printed to fit securely.
Remote connection established to Intel Edison chip attached to the car using websockets.
Input sent to the Intel Edison only upon a change in the input signal instruction string.

Input read to a file in the Intel Edison, which was then read by a C program on the Edison and had instructions fed into the arduino board hosting the Edison, which in turn sent commands to the stepper motors to act accordingly.

Functions included: 
  - Move forward (both hands present facing down)
  - Move backward (both hands present facing up)
  - Turn right (right hand present facing down)
  - Turn backward right (right hand present facing up)
  - Turn left (left hand present facing down)
  - Turn backward left (left hand present facing up)
  - Stop moving (no hands present)

Videos of it working:
  1. https://vimeo.com/117357460
  2. https://vimeo.com/117357461

Team: 
- Alec Huang, Senior at University of the Sciences in Philadelphia. 
- Sakib Jalal, Freshman ar Rutgers University, New Brunswick. 
- Allan Michel, Junior at Drexel University, Philadelphia. 
- Feiyeung Xue, Junior at Drexel University, Philadelphia. 
