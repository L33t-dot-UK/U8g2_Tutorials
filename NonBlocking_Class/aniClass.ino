class animation
{    
    public:
        animation(int WIDTH, int HEIGHT, int FDELAY, int XINCREMENT, int YINCREMENT, int STARTXPOS, int ENDXPOS, int STARTYPOS, int ENDYPOS,  int FRAMES);
        void chkAnimation(boolean toMove);
        boolean toIncrement();
        int getXpos();
        int getYpos();
        int getCurrentFrame();
        int getWidth();
        int getHeight();
        
    private:
        int fDelay;
        int xIncrement;
        int yIncrement;
        int startxPos;
        int endxPos;
        int startyPos;
        int endyPos;
        int frames_;
        boolean barEndX;
        boolean barEndY;

        int currentXpos;
        int currentYpos;
        int currentFrame;
        int width_;
        int height_;

        int timerStart;
        boolean moveAni();
};

//Constructor
animation::animation(int _width, int _height, int _fDelay, int _xIncrement, int _yIncrement, int _startxPos, int _endxPos, int _startyPos, int _endyPos, int _frames)
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
void animation::chkAnimation(boolean toMove)
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
boolean animation::toIncrement()
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
boolean animation::moveAni()
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
int animation::getXpos()
{
    return currentXpos;
}

int animation::getYpos()
{
    return currentYpos;
}
int animation::getCurrentFrame()
{
    return currentFrame;
}
int animation::getWidth()
{
    return width_;
}
int animation::getHeight()
{
    return height_;
}
//---------------------------- END OF ANIMATION CLASS ------------------------------------------


/*
 * THE BELOW CODE IS NEEDED BECAUSE OF THE WAY THAT ARDUINO IDE COMPILIES CODE ONCE A LIBRARY IS CREATED THIS WILL BE DONE DIFFERENTLY
 */
//            WIDTH   HEIGHT                        FRAME_DELAY     XINCREMENT   YINCREMENT   XSTART  XEND   YSTART   YEND   FRAMES        
animation BIRD(icWidth,       icHeight,                  200,          2,            1,        -64,   160,     15,     15,      frames);
animation BIRD1(icWidth_IC2,       icHeight_IC2,         150,          6,            6,        -96,   128,     15,     -8,      frames_IC2);
animation GROUND(groundWidth,       groundHeight,         150,          6,            6,        0,   0,     45,     45,      1);

void increment_BIRD_animation()
{
    BIRD.chkAnimation(true);
    BIRD1.chkAnimation(true);
    GROUND.chkAnimation(false);
    auxScreen.clearBuffer(); 
    auxScreen.drawXBM(GROUND.getXpos(), GROUND.getYpos(), GROUND.getWidth(), GROUND.getHeight(), ground[0]); 
    auxScreen.drawXBM(BIRD.getXpos(), BIRD.getYpos(), BIRD.getWidth(), BIRD.getHeight(), icon[BIRD.getCurrentFrame()]); 
    auxScreen.drawXBM(BIRD1.getXpos(), BIRD1.getYpos(), BIRD1.getWidth(), BIRD1.getHeight(), icon2[BIRD1.getCurrentFrame()]); 
    auxScreen.sendBuffer(); 
}
