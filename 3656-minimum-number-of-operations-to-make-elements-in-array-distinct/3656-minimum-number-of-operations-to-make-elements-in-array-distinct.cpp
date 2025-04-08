class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int,int>mpp;
        int el=-1;
        for(int i=nums.size()-1;i>=0;i--){
            if(mpp.find(nums[i])==mpp.end()) mpp[nums[i]]++;
            else{
                el=i;
                break;
            }
        }
        if (el==-1) return 0;
        el=el+1;
        int ans=el/3;
        if(el%3!=0) ans++;
        
        return ans;
    }
};