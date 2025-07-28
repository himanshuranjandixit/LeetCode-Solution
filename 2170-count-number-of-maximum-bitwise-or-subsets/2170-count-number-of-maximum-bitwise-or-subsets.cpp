class Solution {
public:
    int ans=0;
    void solve(vector<int>& nums, int indx, int curror, int maxorr){
        if(indx>=nums.size()){
            if(curror==maxorr) ans++;
            return ;
        }
        if(curror<=maxorr){
            solve(nums,indx+1,curror|nums[indx],maxorr);
        }
        solve(nums,indx+1,curror,maxorr);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int maxorr = nums[0];
        for(int i=1;i<nums.size();i++){
            maxorr |=nums[i];
        }
        solve(nums,0,0,maxorr);
        return ans;

        
    }
};