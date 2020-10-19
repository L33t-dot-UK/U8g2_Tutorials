# Simple Animation Library Version 1.0.0

# Installation

To install the library download this repo, open Arduino IDE;
- Select "Sketch" -> "Include Library" -> "Add .Zip Library"

Then navigate to "L33T_Animation.zip" (it's in the Library folder) select it and click "Open"

# Libraray Reference

Constructor

  L33T_Animation Animation1(WIDTH, HEIGHT, FRAME_DELAY, XINC, YINC, STARTX, ENDX, STARTY, ENDY, NO_FRAMES);
  
  The above line is the constructor to create an animation object named Animation1. All of the arguments are integers and they   describe the animations size and location.
  
  WIDTH = Width if the animaiton in pixels \
  HEIGHT = Height if the animaiton in pixels \
  FRAME_DELAY = Time in mS between each frame \
  XINC = How many pixels to increment the X axis per iteration \
  YINC = How many pixels to increment the Y axis per iteration \
  STARTX = Start position for the X axis \
  ENDX = End position for the x axis \
  STARTY = Start psoition for the Y axis \
  ENDY = End position for the Y axis \
  NO_FRAMES = Number of frames in the animation \
