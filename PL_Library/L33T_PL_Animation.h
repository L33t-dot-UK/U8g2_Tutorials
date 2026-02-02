class L33T_PL_Animation
{    
    public:
        L33T_PL_Animation(int WIDTH, int HEIGHT, int FDELAY, int XINCREMENT, int YINCREMENT, int STARTXPOS, int ENDXPOS, int STARTYPOS, int ENDYPOS,  int FRAMES);
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

        unsigned long timerStart;
        boolean moveAni();
};

