class Solution {
public:
    int findClosest(int x, int y, int z) {
        int one = abs(x-z);
        int two = abs(y-z);
        if(one<two) return 1;
        else if(two<one) return 2;
        return 0;
        
    }
};