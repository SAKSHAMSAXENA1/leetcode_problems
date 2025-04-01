class Robot {
public:
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1}; // east,north,west,south
int ltX[4]={0,0,0,0},ltY[4]={0,0,0,0};
int w,h;
string directions[4]={"East","North","West","South"};
int dir,x,y,width,height;
    Robot(int width, int height) {
        x=y=dir=0;
        w=width;
        h=height;
        ltX[0]=width-1;
        ltY[1]=height-1;
    }
    
    void step(int num) {
        if(2*(w+h)-4>0)
        num%=(2*(w+h)-4);
        else num%=4;

        if(x==0 && y==0) 
        {
            dir=3; // initially robot was at (0,0) so now after movement it faces South
        }
        
        while(num)
        {
            int stepsToExtremes=abs((ltX[dir]-x)*dx[dir])+abs((ltY[dir]-y)*dy[dir]);
            int stepsTaken=min(num,stepsToExtremes);
            
            x=x+dx[dir]*stepsTaken;
            y=y+dy[dir]*stepsTaken;
            num-=stepsTaken;

            if(num) dir=(dir+1)%4;
        }
    }
    
    vector<int> getPos() {
        return {x,y};
    }
    
    string getDir() {
        return directions[dir];
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */