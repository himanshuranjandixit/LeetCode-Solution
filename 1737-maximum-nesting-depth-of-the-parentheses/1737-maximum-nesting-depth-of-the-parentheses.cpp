class Solution {
public:
    int maxDepth(string s) {
        int ans=0;
        int left=0;
        int right=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') left++;
            else if (s[i]==')') right++;
            ans=max(ans,left-right);
            
        }
        return max(ans,left-right);
        
    }
};