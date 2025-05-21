class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        vector<int>v(k,0);
        int l=0;
        int r=0;
        int indx=0;
        int small=0;
        int ans=0;
        int org=k;
        if(k==0){
            while(r<nums.size()){
                if(nums[r]==0){
                    while( r<nums.size() && nums[r]==0){
                        r++;
                    }
                    l=r;
                    if(l!=nums.size()) ans=max(ans,1);
                }
                else{
                    r++;
                }
                ans=max(ans,r-l);
            }
            return ans;
        }
        while(r<nums.size()){
            if(nums[r]==0 && k>0){
                v[indx]=r;
                indx=(indx+1)%org;
                r++;
                k--;
            }
            else if(nums[r]==0 && k==0){
                l=v[small]+1;
                small=(small+1)%org;
                v[indx]=r;
                indx=(indx+1)%org;
                r++;
            }
            else{
                r++;
            }
            ans=max(ans,r-l);
        }
        return ans;
    }
};