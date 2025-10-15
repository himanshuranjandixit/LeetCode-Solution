class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int c = 1;
        vector<int> a;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i-1]) {
                c++;
            } else {
                a.push_back(c);
                c = 1;
            }
        }
        
        a.push_back(c);

        if (nums.size() == 1) {
            return nums[0] / 2;
        }

        int k = a[0] / 2;
        for (int i = 1; i < a.size(); i++) {
            k = max(min(a[i], a[i-1]), k);
            k = max(k, a[i] / 2);
        }

        return k;
    }
};