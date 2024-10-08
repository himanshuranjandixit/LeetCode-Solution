class Solution {
public:
    int minSwaps(string s) {
        int count=0;
        int ans=INT_MIN;
        for(int i=0;i<s.size();i++){
            if(s[i]=='[') count--;
            else count++;
            ans=max(ans,count);
        }
        if(ans%2!=0) return (ans+1)/2;
        return ans/2;;
        
    }
};