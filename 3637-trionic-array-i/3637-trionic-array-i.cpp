class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int indx=-1;
        int n = nums.size();
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i+1]>nums[i]) continue;
            else{
                indx=i;
                break;
            }
        }
        if(indx== 0 || indx==n-1 || indx==-1) return false;
        int indx2=-1;
        for(int i =indx;i<nums.size()-1;i++){
            if(nums[i+1]<nums[i]) continue;
            else{
                indx2=i;
                break;
            }
        }
        if(indx2==indx || indx2==n-1 || indx2==-1) return false;
        int indx3 = -1;
        for(int i=indx2;i<nums.size()-1;i++){
            if(nums[i+1]>nums[i]) indx3=i;
            else return false;
        }
        return true;
        
    }
};