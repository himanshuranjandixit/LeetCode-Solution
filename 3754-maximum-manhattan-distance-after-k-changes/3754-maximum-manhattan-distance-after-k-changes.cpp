class Solution {
public:
    int maxDistance(string s, int k) {
        int ans=0;
        int x=0;
        int y=0;
        int distance=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='N'){
                y++;
            } 
            else if(s[i]=='S'){
                y--;
            } 
            else if(s[i]=='E'){
                x++;
            } 
            else if(s[i]=='W'){
                x--;
            } 
            ans =max(ans,min(abs(x)+abs(y) + 2*k,i+1));
        } 
        return ans;

        // return min(distance+k,s.size());
        
    }
};