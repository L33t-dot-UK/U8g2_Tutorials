#include "Arduino.h"
#include "L33T_Animation.h"


//Constructor
L33T_Animation::L33T_Animation(int _width, int _height, int _fDelay, int _xIncrement, int _yIncrement, int _startxPos, int _endxPos, int _startyPos, int _endyPos, int _frames)
{
    //Assign values to class variables
    width_ = _width;
    height_ = _height;
    fDelay = _fDelay;
    xIncrement = _xIncrement;
    yIncrement = _yIncrement;
    startxPos = _startxPos;
    endxPos = _endxPos;
    startyPos = _startyPos;
    endyPos = _endyPos;
    frames_ = _frames;
     
    currentFrame = 0;
    currentXpos = startxPos;
    currentYpos = startyPos;  

    barEndX = true;
    barEndY = true;

    boolean aniCompleted = false;
}

//Executes every loop iteration and decides if we need to increment the next frame
void L33T_Animation::chkAnimation(boolean toMove)
{  
    if (toMove)
    {
        moveAni();
    }
    if (toIncrement())
    {        
        currentFrame = currentFrame + 1;
        if (currentFrame == frames_)
        {
            aniCompleted = true;
            currentFrame = 0;
        }
        else
        {
            aniCompleted = false;
        }
    }
    else
    {
        //Don't increment animation
    }
}

//Returns a value depending on if the delay value has been met
boolean L33T_Animation::toIncrement()
{
    if ((millis() - timerStart) > fDelay)
    {
        timerStart = millis();
        return true;
    }
    else
    {
        return false;
    }
}

//Looks at the x and y end coords and evaluates if they have been exceeded
boolean L33T_Animation::moveAni()
{
     boolean returnVal = true;
   
        if(startxPos > endxPos)
        {
            //moving from right to left
            if (currentXpos >= endxPos)
            {
                currentXpos = currentXpos - xIncrement;
                returnVal = true;
                barEndX = true; 
            }
            else
            {
                barEndX = false;
                returnVal = false;
            }
        }
        else if (startxPos <= endxPos)
        {
            //moving from left to right
            if (currentXpos < endxPos)
            {
                currentXpos = currentXpos + xIncrement;
                returnVal = true;
                barEndX = true;
            }
            else
            {
                barEndX = false;
                returnVal = false;
            }
        }
        
        if (startyPos > endyPos)
        {
            //moving from top to bottom
            if (currentYpos >= endyPos)
            {
                currentYpos = currentYpos - yIncrement;
                returnVal = true;
                barEndY = true;
            }
            else
            {
                barEndY = false;
                returnVal = false;
            }
        }
        else if (startyPos <= endyPos)
        {
            //moving from bottom to top
            if (currentYpos < endyPos)
            {
                currentYpos = currentYpos + yIncrement;
                returnVal = true;
                barEndY = true;
            }
            else
            {
                barEndY = false;
                returnVal = false;
            }
        }

     if(barEndY == false && barEndX == false)
     {
        //Taken out because a bug, use the restAni method after each iteration
         //currentXpos = startxPos;
         //currentYpos = startyPos;
     }

/*
     Serial.print("x POS = " );
     Serial.print(currentXpos);
     Serial.print( " ::: Y POS = ");
     Serial.println(currentYpos);
*/   
     return returnVal;
}

//Helper methods
int L33T_Animation::getXpos()
{
    return currentXpos;
}

int L33T_Animation::getYpos()
{
    return currentYpos;
}
void L33T_Animation::setXpos(int pos)
{
    currentXpos = pos;
}
void L33T_Animation::setYpos(int pos)
{
    currentYpos = pos;
}
int L33T_Animation::getCurrentFrame()
{
    return currentFrame;
}
int L33T_Animation::getWidth()
{
    return width_;
}
int L33T_Animation::getHeight()
{
    return height_;
}
boolean L33T_Animation::isComplete()
{
    return aniCompleted;
}
void L33T_Animation::moveX(int pixels)
{
    currentXpos = currentXpos + pixels;
}
void L33T_Animation::moveY(int pixels)
{
    currentYpos = currentYpos + pixels;
}

boolean L33T_Animation::getBarEndX()
{
    return barEndX;
}

boolean L33T_Animation::getBarEndY()
{
    return barEndY;
}

void L33T_Animation::resetAni()
{
    currentXpos = startxPos;
    currentYpos = startyPos;
    barEndX = true;
    barEndY = true;

}
boolean L33T_Animation::toReset()
{
    if(barEndY == false && barEndX == false)
    {
        return true;
    }
    else
    {
        return false;
    }

}