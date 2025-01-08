class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long sum =accumulate(nums.begin(),nums.end(),0LL);
        int valid_split=0;
        long long int summ=0;
        for(int i=0;i<nums.size()-1;i++){
            summ+=nums[i];
            long long diff=sum-summ;
            if(summ>=diff){
                valid_split++;
            }
        }
        return valid_split                                                      ;
        
    }
};