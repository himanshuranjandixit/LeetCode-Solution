class Solution {
public:
    string clearStars(string s) {
        // string ans;
        // multiset<char>mst;
        // for(int i=0;i<s.size();i++){
        //     char ch = s[i]; 
        //     if(ch=='*'){
        //         char minichar = *mst.begin();
        //         mst.erase(mst.begin());
        //         for(int i=ans.size()-1;i>=0;i--){
        //             if(ans[i]==minichar){
        //                 ans.erase(ans.begin()+i);
        //                 break;
        //             }
        //         }
        //     }
        //     else{
        //         mst.insert(ch);
        //         ans.push_back(ch);
        //     }
        // }
        // return ans;

        unordered_map<int,int>indx;
        vector<stack<int>>v(26);
        for(int i=0;i<s.size();i++){
            char ch = s[i];
            if(ch=='*'){
                for(int i=0;i<26;i++){
                    if(!v[i].empty()){
                        int index = v[i].top();
                        v[i].pop();
                        indx[index]=0;
                        break;
                    }
                }
            }
            else{
                indx[i]=1;
                v[ch-'a'].push(i);
            }
        }
        string ans="";
        for(int i=0;i<s.size();i++){
            if(indx[i]) ans+=s[i];
        }
        return ans;

        
    }
};