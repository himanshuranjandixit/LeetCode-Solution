class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int diff=INT_MAX;
        int ans=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++){
            for(int j=i+1;j<nums.size()-1;j++){
                for(int k=j+1;k<nums.size();k++){
                    int sum = nums[i]+nums[j]+nums[k];
                    int difference = abs(target - sum);
                    if(diff>difference){
                        diff =difference;
                        ans= sum;
                    }

                }
            }
        }
        return ans;
        
    }
};