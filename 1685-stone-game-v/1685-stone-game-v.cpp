class Solution {
public:
    vector<int>prefix;
    int dp[501][501];
    int solve(vector<int>& stone , int start, int end){
        if(start == end) return 0;
        if(dp[start][end]!=-1) return dp[start][end];
        int res= 0;
        int leftsum=0;
        int rightsum=0;
        for(int i=start +1 ; i<=end;i++){
            leftsum = prefix[i] - prefix[start];
            rightsum = prefix[end+1]-prefix[i];
            if(leftsum>rightsum){
                res = max(res, rightsum + solve(stone,i,end));
            }
            else if(rightsum>leftsum){
                res= max(res, leftsum + solve(stone,start,i-1));
            }
            else res= max(res, leftsum + max(solve(stone, start, i-1), solve(stone, i, end)));
        }
        return dp[start][end] = res ;
    }
    int stoneGameV(vector<int>& stone) {
        if(stone.size()==1) return 0;
        int sum= stone[0];
        prefix.resize(stone.size()+1,0);
        prefix[0] = 0;
        for(int i=0;i<stone.size();i++){
            prefix[i+1] = prefix[i] + stone[i]; 
        }
        memset(dp,-1, sizeof(dp));
        return solve(stone,0,stone.size()-1);
        
    }
};