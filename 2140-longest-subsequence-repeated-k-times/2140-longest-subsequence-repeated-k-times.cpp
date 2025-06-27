class Solution {
public:
    bool isvalid(const string& sub, const string& temp, int k){
        string s="";
        for(int i=0;i<k;i++){
            s+=sub;

        }
        int i=0;int j=0;
        while(i<s.size() && j<temp.size()){
            if(s[i]==temp[j]){
                i++;
            }
            j++;
        }
        if(i==s.size()) return true;
        return false;
    }


    string longestSubsequenceRepeatedK(string s, int k) {
        unordered_map<char,int>mpp;
        for(auto it : s){
            mpp[it]++;
        }
        vector<char>c;
        for(auto &it:mpp){
            it.second/=k;
            if(it.second) c.push_back(it.first);
        }
        sort(c.begin(),c.end(),greater<int>());
        queue<string>q;
        q.push("");
        string ans="";
        while(!q.empty()){
            string curr = q.front();
            q.pop();
            for(char &ch :c){
                string next = curr + ch;
                if(isvalid(next,s,k)){
                    q.push(next);
                    if(next.size()>ans.size() || (ans.size()==next.size() && next > ans)){
                        ans = next;
                    }

                }
            }
        }
        return ans;
    }
};