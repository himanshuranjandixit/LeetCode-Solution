class Solution {
public:
int maxOr;
vector<int>ans;
    void solve(vector<int>& nums, int indx, int start,int currOr,int size){
        if(indx==nums.size()){
            if(currOr== maxOr && start!=-1){
                ans[start] = min(ans[start],size);
            }
            return ;
        }
        if(start==-1){
            solve(nums,indx+1,indx,currOr|nums[indx],size+1);
        }
        if(start!=-1 && currOr<=maxOr){
            solve(nums,indx+1,start,currOr|nums[indx],size+1);
        }
        solve(nums,indx+1,start,currOr,size);
       
    }
    vector<int> smallestSubarrays(vector<int>& nums) {
        maxOr = nums[0];
        for(int i=1;i<nums.size();i++){
            maxOr |=nums[i];
        }
        ans.resize(nums.size(),-1);
        // solve(nums,0,-1,0,0);
        // return ans;
        vector<int>v(32,-1);
        for(int i=nums.size()-1;i>=0;i--){
            int num = nums[i];
            int nextindx = i;
            for(int j=0;j<32;j++){
                if(!(num&(1<<j))){
                    nextindx=max(nextindx,v[j]);
                }
                else{
                  v[j]=i;
                }
            }
            ans[i]=nextindx-i+1;
            
        }
        return ans;


        
    }
};