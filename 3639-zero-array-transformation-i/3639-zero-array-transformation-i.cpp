class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int>freq(nums.size()+1,0);
        for(auto it : queries){
            freq[it[0]]++;
            freq[it[1]+1]--;
        }
        for(int i=1;i<freq.size();i++){
            freq[i]+=freq[i-1];
        }
        for(int i=0;i<nums.size();i++){
            nums[i]=max(0,nums[i]-freq[i]);
            if(nums[i]!=0) return false;
        }
        return true;
        
    }
};