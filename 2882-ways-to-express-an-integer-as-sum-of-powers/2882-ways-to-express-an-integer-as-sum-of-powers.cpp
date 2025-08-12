class Solution {
public:
int cnt =0;
int m = 1e9 +7;
int N;
int memo[301][305];
    int solve(int n , int x, long long sum){
        if(sum==N) return 1;
        if(sum>N) return 0;
        if(n>N) return 0;
        if(memo[n][sum]!=-1) return memo[n][sum];
        int val = int(pow(n,x));
        if(val>N) return memo[n][sum]=0;
        int take =0;
        int not_take =0;
        take = solve(n+1,x,sum + val) %m;
        not_take = solve(n+1,x,sum)%m;
        return memo[n][sum] = (take + not_take)%m;
    }
    int numberOfWays(int n, int x) {
        N=n;
        memset(memo,-1,sizeof(memo));
        long long sum=0;
        return solve(1,x,sum);

    }
};