class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int mini = nums[0];
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] - mini>k){
                mini= nums[i];
                count++;
                cout<<count<<" "<<mini<<endl;
            }
        }
        count++;
        return count;
        
    }
};