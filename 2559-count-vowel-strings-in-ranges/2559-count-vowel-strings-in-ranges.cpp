class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int>v(words.size());
        int sum=0;
        vector<int>ans(queries.size());
        for(int i=0;i<words.size();i++){
             if(words[i][0]=='a' || words[i][0]=='e' || words[i][0]=='i' || words[i][0]=='o' || words[i][0]=='u'){
                if(words[i][words[i].size()-1]=='a' || words[i][words[i].size()-1]=='e' || words[i][words[i].size()-1]=='i' || words[i][words[i].size()-1]=='o' || words[i][words[i].size()-1]=='u'){
                    sum++;
                }
             }
             v[i]=sum;
        }
        for(int i=0;i<queries.size();i++){
            if(queries[i][0]==0){
                ans[i]=v[queries[i][1]];
            }
            else ans[i]=v[queries[i][1]]-v[queries[i][0]-1];
        }
        return ans ;
        
    }
};