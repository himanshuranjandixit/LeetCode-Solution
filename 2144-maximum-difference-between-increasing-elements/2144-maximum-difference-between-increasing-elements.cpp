class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int mini = INT_MAX;
        int diff = INT_MIN;
        for(auto it : nums){
           diff=max(diff, it-mini);
           mini=min(mini,it);
        }
        if(mini==INT_MAX || diff==INT_MIN) return -1;
        if(diff<=0) return -1;
        return diff;

        
    }
};