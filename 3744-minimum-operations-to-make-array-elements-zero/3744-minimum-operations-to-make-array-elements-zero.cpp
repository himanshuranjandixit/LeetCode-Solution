class Solution {
public:
    long long countNumbersWithSteps(int k, long long l, long long r) {
        long long low = pow(4LL, k - 1);
        long long high = pow(4LL, k) - 1;
        if (r < low || l > high) return 0;
        return max(0LL, min(r, high) - max(l, low) + 1);
    }

    long long computeOperations(long long l, long long r) {
        long long totalSteps = 0;
        int maxK = 0;
        long long temp = r;
        while (temp > 0) {
            temp /= 4;
            maxK++;
        }
        for (int k = 1; k <= maxK; ++k) {
            long long count = countNumbersWithSteps(k, l, r);
            totalSteps += count * k;
        }
        return (totalSteps + 1) / 2;
    }
    long long minOperations(vector<vector<int>>& queries) {
       long long result = 0;
        for (auto& q : queries) {
            long long l = q[0], r = q[1];
            result += computeOperations(l, r);
        }
        return result;
    }
};