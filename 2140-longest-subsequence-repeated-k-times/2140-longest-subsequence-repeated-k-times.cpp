class Solution {
public:
    unordered_map<string,int> ans;
    bool check=false;
    string res;
    void solve(string s, unordered_map<char,int>& mpp,int indx, string& temp,int k){
        if(indx==s.size() || temp.size()==7){
            
            if(!isvalid(temp,s,k) ) return;
            ans[temp]++;
            return;
        }
        if(mpp[s[indx]]){
            temp+=s[indx];
            mpp[s[indx]]--;
            solve(s,mpp,indx+1,temp,k);
            temp.pop_back();
            mpp[s[indx]]++;
        }
        solve(s,mpp,indx+1,temp,k);
    }

    bool isvalid(const string& sub, const string& temp, int k){
        string s="";
        for(int i=0;i<k;i++){
            s+=sub;

        }
        // cout<<s<<endl;
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
        string ss="";
        vector<char>c;
        for(auto &it:mpp){
            it.second/=k;
            if(it.second) c.push_back(it.first);
        }
        // solve(s,mpp,0,temp,k);
        // string result="";
        // for(auto it :ans){
        //     if(it.first.size()>result.size()){
        //         result =it.first;

        //     }
        //     else if(it.first.size()==result.size()){
        //         result = max(result,it.first);
        //     }
        // }
        // return result;


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