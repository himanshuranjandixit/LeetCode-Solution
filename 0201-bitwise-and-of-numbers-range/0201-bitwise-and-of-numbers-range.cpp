class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        long long ans=0;
        if(left==right) return left;
        for(int i=31;i>=0;i--){
            if((left&(1<<i))==(right&(1<<i))){
                ans= (ans|((left&(1<<i))));
            }
            else break;
        }
        return ans;
        
    }
};