class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int count=0;
        vector<int>temp;
        for(int i=0;i<nums.size();i++){
            if(count<3){
                temp.push_back(nums[i]);
                count++;
            }
            if(count==3){
                for(int j=0;j<3;j++){
                    for(int l =0;l<3;l++){
                        if(temp[j]-temp[l]>k) return  {};
                    }
                }
                ans.push_back(temp);
                count=0;
                temp.clear();

            }
        }
        if(count==3){
            for(int j=0;j<3;j++){
                for(int l =0;l<3;l++){
                    if(temp[j]-temp[l]>k) return  {};
                }
            }
            ans.push_back(temp);
            count=0;
            temp.clear();

        }
        
        return ans;
    }
};