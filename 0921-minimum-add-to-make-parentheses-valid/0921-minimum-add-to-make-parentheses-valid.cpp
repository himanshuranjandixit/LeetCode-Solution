class Solution {
public:
    int minAddToMakeValid(string s) {
        int count=0;
        int maxi=INT_MIN;
        int mini=INT_MAX;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') count--;
            else count ++;
            maxi=max(count,maxi);
            mini=min(count,mini);
        }
        if(count==0) return 0;
        if(maxi<0)maxi=maxi*(-1);
        if(mini<0)mini=mini*(-1);
        if(mini>maxi) return mini;
        return maxi;
        
    }
};