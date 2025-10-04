class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n - 1;
        int res = 0;
        while(l<r){
            int x = r - l;
            int y = min(height[l], height[r]);
            res = max(res, x * y); 
            if(height[l] < height[r]) l++;
            else r--;
        }
        return res;     
    }
};