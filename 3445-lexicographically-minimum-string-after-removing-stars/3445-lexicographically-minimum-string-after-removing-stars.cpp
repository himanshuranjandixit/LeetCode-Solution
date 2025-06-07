class Solution {
public:
    string clearStars(string s) {
        string ans;
        multiset<char>mst;
        for(int i=0;i<s.size();i++){
            char ch = s[i]; 
            if(ch=='*'){
                char minichar = *mst.begin();
                mst.erase(mst.begin());
                for(int i=ans.size()-1;i>=0;i--){
                    if(ans[i]==minichar){
                        ans.erase(ans.begin()+i);
                        break;
                    }
                }
            }
            else{
                mst.insert(ch);
                ans.push_back(ch);
            }
        }
        return ans;
        
    }
};