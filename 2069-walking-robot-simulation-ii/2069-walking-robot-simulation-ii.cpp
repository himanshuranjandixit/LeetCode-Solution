class Robot {
public:
    int pos;
    int p;
    int w,h;
    Robot(int width, int height) {
        w=width;
        h=height;
        p = 2* (w+h-2);
        pos=0;
    } 
    void step(int num) {
        pos+=num;
    }
    
    vector<int> getPos() {
        int pos1 = pos%p;
        // cout<<pos<<" "<<pos1<<endl;
        if(pos1>=0 && pos1<=w-1) return {pos1,0};
        if(pos1>=w && pos1<=w+h-2) return {w-1,pos1-w+1};
        if(pos1>=w+h-1 && pos1<=2*w+h-3) return {2*w+h-3-pos1,h-1};
        
        return {0,p-pos1};
        
        
    }
    
    string getDir() {
        int pos1 = pos%p;
        if(pos==0) return "East";
        if(pos1>0 && pos1<=w-1) return "East";
        if(pos1>=w && pos1<=w+h-2) return "North";
        if(pos1>=w+h-1 && pos1<=2*w+h-3) return "West";
        return "South";
        
         

        
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */