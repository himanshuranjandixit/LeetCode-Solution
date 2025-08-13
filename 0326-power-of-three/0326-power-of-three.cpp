class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<0) return false;
        long long i=1;
        while(true){
            if(i==n) return true;
            if(i>n) return false;
            i=i*3;
        }
        return false;

        
    }
};