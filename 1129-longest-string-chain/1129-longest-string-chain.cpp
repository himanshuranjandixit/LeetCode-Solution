class Solution {
public:
    bool compare(string a, string b){
        if(abs(int(a.size())-int(b.size()))!=1) return false;
        int count=0;
        int i=0;int j=0;
        if(a.size()<b.size()) swap(a,b);
        while(i<a.size() && j<b.size()){
            if(a[i]==b[j]){
                i++;j++;
            }
            else{
                count++;
                i++;
            }
        }
        if(i< a.size()) count++;
        return count==1;
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),[](const string& a, const string& b){
            return a.size()<b.size();
        });
        vector<int>dp(words.size()+1,1);
        int ans=1;
        for(int i=1;i<words.size();i++){
            for(int j=0;j<i;j++){
                if(compare(words[i],words[j]) && dp[j]+1 > dp[i]){
                    dp[i]=dp[j]+1;
                }
            }
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};