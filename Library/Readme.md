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
  NO_FRAMES = Number of frames in the animation

Methods

  void chkAnimation(boolean toMove);
  
  This method will be called each loop iteration and will allow the animation to be animated. It will increment the frame and move the animation. The argument toMove tells the methid is it should move the animation. If it's set to true the animation will move in accordance with the constructor arguments. If it's set to false the animation will not move.
  
  boolean to increment();
  
  This is used internally inside the class however you can access it. It will return false if the FRAME_DELAY has not been exceeded of true if the FRAME_DELAY has been exceeded.
  
int getXpos();

int getYpos();

void setXpos();

void setYpos();

int getCurrentFrame();

int getWidth();

int getHeight();

boolean isComplete();

Returns true if all of the frames in the animation has been played, otherwise false is returned

boolean toReset();

returns true if the ENDX and ENDY coordinates have been exceeded. Allows you to decide if the animations needs to be reset.

void moveX(int pixels);
void moveY(int pixels);

boolean getBarEndX();

boolean getBarEndY();

oid resetAni();

