class FindSumPairs {
public:
    map<long long, int> mpp;
    vector<long long> num1, num2;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        for (int n : nums2) {
            mpp[n]++;
            num2.push_back(n);
        }
        for (int n : nums1) {
            num1.push_back(n);
        }
    }

    void add(int index, int val) {
        long long old_val = num2[index];
        long long new_val = old_val + val;
        mpp[old_val]--;
        if (mpp[old_val] == 0) mpp.erase(old_val);
        mpp[new_val]++;
        num2[index] = new_val;
    }

    int count(int tot) {
        int ans = 0;
        for(long long a : num1){
            long long b = tot - a;
            if (mpp.count(b)) {
                ans += mpp[b];
            }
        }
        return ans;
    }
};
