class Solution {
public:
    int trap(vector<int>& height) {
        int ans=0;
        int left=0;
        int right=height.size()-1;
        int lefty=height[left];
        int righty=height[right];
        while(left<right){
            if(lefty<righty){
                left++;
                lefty=max(lefty,height[left]);
                ans+=lefty-height[left];
            }
            else{
                right--;
                righty=max(righty,height[right]);
                ans+=righty-height[right];
            }

        }
        return ans;
    }
};