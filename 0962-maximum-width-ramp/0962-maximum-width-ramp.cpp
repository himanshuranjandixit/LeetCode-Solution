class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n=nums.size();
        vector<int>indices(n);

        for(int i=0;i<n;i++){
            indices[i]=i;
        }
        sort(indices.begin(),indices.end(),[&](int i,int j){
            if(nums[i]!=nums[j]) return nums[i]<nums[j];
            else return i<j;

        });
        int minIndex=n;
        int maxWidth=0;

        for(int i=0;i<n;i++){
            maxWidth=max(maxWidth,indices[i]-minIndex);
            minIndex=min(minIndex,indices[i]);
        }
        return maxWidth;
    }
};