class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0;
        int y=0;
        for(auto it:moves){
            if(it=='U') y+=1;
            if(it=='D') y-=1;
            if(it=='L') x-=1;
            if(it=='R') x+=1;
        }
        if(x==0 && y==0) return true;
        return false;
        
    }
};