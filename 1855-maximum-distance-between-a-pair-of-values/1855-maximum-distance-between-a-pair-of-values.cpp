class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int ans =0;
        for(int i=0;i<nums1.size();i++){
            int j = lower_bound(nums2.rbegin(),nums2.rend(),nums1[i]) - nums2.rbegin();
            if (j != nums2.size()) {
                j = nums2.size()-j-1;
                if (j >= i) ans = max(ans, j - i);
            }         
        }
        return ans;
        
    }
};