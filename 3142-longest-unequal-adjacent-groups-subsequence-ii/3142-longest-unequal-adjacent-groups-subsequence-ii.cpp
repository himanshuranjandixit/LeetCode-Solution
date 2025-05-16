class Solution {
private:
    bool hamming(string& s1, string& s2){
        int diff=0;
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i])diff++;
            if(diff>1) return false;
        }
        return diff==1;
    }
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        // unordered_map<int,vector<string>>mpp;
        // for(int i=0;i<words.size();i++){
        //     mpp[groups[i]].push_back(words[i]);
        // }
        // vector<int>length(10,0);
        // for(auto it:mpp){
        //     sort(it.second.begin(),it.second.end(),[](string& a, string& b){
        //         return a.size()<b.size();
        //     });
        //     length[it.second[0].size()]++;
        //     for(int i = 1;i<it.second.size();i++){
        //         if(it.second[i].size()==it.second[i-1].size())continue;
        //         length[it.second[i].size()]++;
        //     }
        // }
        // int reqsize=0;
        // int size=0;
        // for(int i=0;i<9;i++){
        //     if(length[i]>size){
        //         size=length[i];
        //         reqsize=i;
        //     }
        // }
        // vector<string>ans;
        // for(auto it : mpp){
        //     for(auto it1 : it.second){
        //         if(it1.size()==reqsize){
        //             ans.push_back(it1);
        //             break;
        //         }
        //     }
        // }
        // vector<string>ans1;
        // for(int i=0;i<words.size();i++){
        //     for(auto it :ans){
        //         if(it==words[i]){
        //             ans1.push_back(it);
        //             break;
        //         }
        //     }
        // }
        // return ans1;
        int n = words.size();
        vector<int>dp(n,1);
        vector<int>prev(n,-1);
        int indx=0;
        int length=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(words[i].size()==words[j].size() && hamming(words[i],words[j])==1 && groups[i]!=groups[j]){
                    if(dp[i]<dp[j]+1){
                        dp[i]=dp[j]+1;
                        prev[i]=j;
                    }
                    if(length<dp[i]){
                        length=dp[i];
                        indx=i;
                    }
                }
            }
        }
        vector<string>ans;
        while(indx!=-1){
            ans.push_back(words[indx]);
            indx=prev[indx];
        }
        reverse(ans.begin(),ans.end());
        return ans;


        
    }
};