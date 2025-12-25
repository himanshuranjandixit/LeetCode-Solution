class Solution {
public:
    unordered_map<long long,int>mpp;
    int solve(string &s, long long indx, long long unique, bool canchange, int k){
        if(indx==s.size()) return 0;
        long long key =(indx<<27) |(unique<<1) | canchange ;
        if(mpp.count(key)) return mpp[key];
        int res = 0;
        int updateunique = unique | (1<<(s[indx]-'a'));
        int cnt = __builtin_popcount(updateunique);
        if(cnt<=k){
            res = solve(s,indx+1,updateunique,canchange,k);
        }
        else{
            res = 1+solve(s,indx+1,1<<(s[indx]-'a'),canchange,k);
        }
        if(canchange){
            for(int i=0;i<26;i++){
                int updateunique = unique | (1<<i);
                int cnt = __builtin_popcount(updateunique);
                if(cnt<=k){
                    res = max(res,solve(s,indx+1,updateunique,false,k));
                }
                else{
                    res = max(res,1+solve(s,indx+1,1<<i,false,k));
                }
            }
        }
        return mpp[key]=res;
    }
    int maxPartitionsAfterOperations(string s, int k) {
        return solve(s,0,0,true,k)+1;
        
    }
};