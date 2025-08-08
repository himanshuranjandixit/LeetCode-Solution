//ajay 
#include <bits/stdc++.h>
using namespace std;

class Solution {
    double memo[205][205];

    double solve(int a, int b) {
        // Base cases
        if (a <= 0 && b > 0) return 1.0;
        if (a <= 0 && b <= 0) return 0.5;
        if (a > 0 && b <= 0) return 0.0;

        if (memo[a][b] >= 0) return memo[a][b];

        double prob = 0.25 * (
            solve(a - 4, b) +
            solve(a - 3, b - 1) +
            solve(a - 2, b - 2) +
            solve(a - 1, b - 3)
        );

        return memo[a][b] = prob;
    }

public:
    double soupServings(int n) {
        if (n > 5000) return 1.0; 

        memset(memo, -1, sizeof(memo));
        int units = ceil(n / 25.0);
        return solve(units, units);
    }
};