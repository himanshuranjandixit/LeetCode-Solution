class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mini=INT_MAX;
        int maxi = INT_MIN;
        int minindex=-1;
        int maxindex=-1;
        for(int i=0;i<nums.size();i++){
            if(mini>nums[i]){
                mini=nums[i];
                minindex=i;
            }
            if(maxi<nums[i]){
                maxi=nums[i];
                maxindex=i;
            }
        }
        cout<<maxindex<<" "<<minindex<<endl;
        if(maxindex>minindex){
            swap(maxindex,minindex);
        }
        cout<<maxindex<<" "<<minindex<<endl;
        //max min
        int ans= maxindex+1+nums.size()-minindex;
        cout<<ans<<endl;
        ans=min(ans,minindex+1);
        cout<<ans<<endl;
        ans=min(ans,(int)nums.size()-maxindex);

        //min max
        return ans;



        
    }
};