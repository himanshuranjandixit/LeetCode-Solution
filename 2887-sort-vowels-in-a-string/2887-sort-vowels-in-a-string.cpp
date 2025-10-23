class Solution {
public:
    string sortVowels(string s) {
        vector<char>v;
        unordered_map<char,bool>mpp;
        mpp['a']=true; mpp['A']=true;mpp['e']=true;mpp['E']=true;mpp['i']=true;mpp['I']=true;mpp['o']=true;mpp['O']=true;mpp['u']=true;mpp['U']=true;
        for(auto &it : s){
            if(mpp.count(it)){
                v.push_back(it);
            }
        }
        sort(v.begin(),v.end());
        int i=0;
        for(auto &it :s){
            if(mpp.count(it)){
                it=v[i];
                i++;
            }
        }
        return s;
        
    }
};