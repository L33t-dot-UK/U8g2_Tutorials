class L33T_Animation
{    
    public:
        L33T_Animation(int WIDTH, int HEIGHT, int FDELAY, int XINCREMENT, int YINCREMENT, int STARTXPOS, int ENDXPOS, int STARTYPOS, int ENDYPOS,  int FRAMES);
        void chkAnimation(boolean toMove);
        boolean toIncrement();
        int getXpos();
        int getYpos();
        void setXpos(int pos);
        void setYpos(int pos);
        int getCurrentFrame();
        int getWidth();
        int getHeight();
	boolean isComplete();
        boolean toReset();
	void moveX(int pixels);
	void moveY(int pixels);
        boolean getBarEndX();
        boolean getBarEndY();
        void resetAni();
        
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

        boolean aniCompleted;
};
