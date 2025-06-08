class Solution {
public:
    vector<int> lexicalOrder(int n) {
        set<string>v;
        for(int i=1;i<=n;i++){
            string s = to_string(i);
            v.insert(s);
        }
        // sort(v.begin(),v.end(),[](const string& a, const string& b){
        //     return a<b;

        // });
        vector<int>ans;
        for(auto it:v){
            ans.push_back(stoi(it));
        }
        return ans;
        
    }
};