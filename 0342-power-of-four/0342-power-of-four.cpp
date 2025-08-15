class Solution {
public:
    bool isPowerOfFour(int n) {
        long long num =1;
        if(n<0) return false;
        while(true){
            if(num==n) return true;
            if(num>n) return false;
            num *= 4;
        }
        return false;
        
    }
};