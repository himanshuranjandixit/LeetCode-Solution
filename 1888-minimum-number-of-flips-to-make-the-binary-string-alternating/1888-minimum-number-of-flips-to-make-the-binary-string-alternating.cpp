class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        string t =s+s;
        string altr1 ="";
        string altr2="";
        for(int i=0;i<2*n;i++){
            altr1 += (i%2 ? '1' : '0');
            altr2 += (i%2 ? '0' : '1');
        }
        int diff1=0;
        int diff2=0;
        int l=0;
        int ans=INT_MAX;
        for(int r =0;r<2*n;r++){
            if(t[r]!=altr1[r]) diff1++;
            if(t[r] != altr2[r]) diff2++;
            if(r-l+1>n){
                if(t[l]!=altr1[l]) diff1--;
                if(t[l] != altr2[l]) diff2--;
                l++;
            }
            if(r-l+1==n) ans=min(ans,min(diff1,diff2));
        }
        return ans;
    }
};