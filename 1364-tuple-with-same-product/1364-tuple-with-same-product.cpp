class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int ans=0;
        map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                mpp[nums[i]*nums[j]]++;
            }
        }
        for(auto it :mpp){
            if(it.second>=2){
                ans+=(it.second*(it.second-1)/2)*8;
            }
        }
        return ans;
    }
};