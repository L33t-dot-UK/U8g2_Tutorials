# Simple Animation Library Version 1.0.0

REFERENCE: https://github.com/L33t-dot-UK/U8g2_Tutorials/tree/master/Library

# Installation

To install the library download this repo, open Arduino IDE;
- Select "Sketch" -> "Include Library" -> "Add .Zip Library"

Then navigate to "L33T_Animation.zip" (it's in the Library folder) select it and click "Open"

# Library Reference

## Constructor

  ### L33T_Animation Animation1(WIDTH, HEIGHT, FRAME_DELAY, XINC, YINC, STARTX, ENDX, STARTY, ENDY, NO_FRAMES);
  
  The above line is the constructor to create an animation object named Animation1. All of the arguments are integers and they   describe the animations size and location.
  
  __WIDTH = Width if the animaiton in pixels \
  HEIGHT__ = Height if the animaiton in pixels \
  __FRAME_DELAY__ = Time in mS between each frame \
  __XINC__ = How many pixels to increment the X axis per iteration \
  __YINC__ = How many pixels to increment the Y axis per iteration \
  __STARTX__ = Start position for the X axis \
  __ENDX__ = End position for the x axis \
  __STARTY__ = Start psoition for the Y axis \
  __ENDY__ = End position for the Y axis \
  __NO_FRAMES__ = Number of frames in the animation

## Methods

  ### void chkAnimation(boolean toMove);
  
  This method will be called each loop iteration and will allow the animation to be animated. It will increment the frame and move the animation. The argument toMove tells the method is it should move the animation. If it's set to true the animation will move in accordance with the constructor arguments. If it's set to false the animation will not move.
  
  ### boolean to increment();
  
  This is used internally inside the class however you can access it. It will return False if the __FRAME_DELAY__ has not been exceeded or True if the __FRAME_DELAY__ has been exceeded.
  
### int getXpos();

Returns the X coordinate of the animation

### int getYpos();

Returns the Y coordinate of the animation

### void setXpos();

Sets the X coordinate of the animation

### void setYpos();

Sets the Y coordinate of the animation

### int getCurrentFrame();

Returns the current frame in the animation from 0 to (__NO_FRAMES__ - 1)

### int getWidth();

Returns the width of the animaiton

### int getHeight();

Returns the height of the animation

### boolean isComplete();

Returns True if all of the frames in the animation has been played, otherwise False is returned

### boolean toReset();

returns True if the __ENDX__ and __ENDY__ coordinates have been exceeded. Allows you to decide if the animations needs to be reset.

### void moveX(int pixels);

Allows you to move the animaiton in the X axis by a number of pixels. Negative numbers will move the animation left

### void moveY(int pixels);

Allows you to move the animaiton in the Y axis by a number of pixels. Negative numbers will move the animation up

### boolean getBarEndX();

Returns False if the animations has exceeded __ENDX__

### boolean getBarEndY();

Returns False if the animation has exceeded __ENDY__

### void resetAni();

Resets the animation to the original constructor arguments
