class Solution {
public:
    int MOD = 1e9+7;

    int num_ways(int n) {
        uint64_t three_perms{6}, two_perms{6}, itr{2};

        for (; itr <= n; ++itr) {
            auto new_threes = (three_perms * 2 % MOD) + (two_perms * 2 % MOD);
            auto new_twos = (three_perms * 2 % MOD) + (two_perms * 3 % MOD);

            three_perms = new_threes;
            two_perms = new_twos;
        }

        return (three_perms + two_perms) % MOD;
    }

    int numOfWays(int n) { return num_ways(n); }
};