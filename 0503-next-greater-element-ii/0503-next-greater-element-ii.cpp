class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int>ans;
        vector<int>v(nums.size());
        for(int i=0;i<nums.size();i++){
            v[i]=nums[i];
        }
        sort(v.begin(),v.end());
        int indx=0;
        for(int i=0;i<nums.size();i++){
            int check=1;
            for(int j=indx;j<nums.size()-1;j++){
                if(nums[i]==v[j] && nums[i]<v[j+1]){
                    ans.push_back(v[j+1]);
                    check=0;

                }
            }
            if(check) ans.push_back(-1);
        }
        return ans;
    }
};