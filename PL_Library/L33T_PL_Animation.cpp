#include "Arduino.h"
#include "L33T_PL_Animation"


//Constructor
L33T_PL_Animation::L33T_PL_Animation(int _width, int _height, int _fDelay, int _xIncrement, int _yIncrement, int _startxPos, int _endxPos, int _startyPos, int _endyPos, int _frames)
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
}

//Executes every loop iteration and decides if we need to increment the next frame
void L33T_PL_Animation::chkAnimation(boolean toMove)
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
            currentFrame = 0;
        }
    }
    else
    {
        //Don't increment animation
    }
}

//Returns a value depending on if the delay value has been met
boolean L33T_PL_Animation::toIncrement()
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
boolean L33T_PL_Animation::moveAni()
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
         currentXpos = startxPos;
         currentYpos = startyPos;
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
int L33T_PL_Animation::getXpos()
{
    return currentXpos;
}

int L33T_PL_Animation::getYpos()
{
    return currentYpos;
}
int L33T_PL_Animation::getCurrentFrame()
{
    return currentFrame;
}
int L33T_PL_Animation::getWidth()
{
    return width_;
}
int L33T_PL_Animation::getHeight()
{
    return height_;
}
