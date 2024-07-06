class Solution {
public:
    int passThePillow(int n, int time) {
        int jadoo= time/(n-1);
        int ranjan = time%(n-1);
        if(jadoo%2==0){
            return ranjan+1;
        }
        return n-ranjan ;
    }
};