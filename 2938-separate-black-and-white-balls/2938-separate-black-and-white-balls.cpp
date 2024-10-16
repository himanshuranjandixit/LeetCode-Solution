class Solution {
public:
    long long minimumSteps(string s) {
        int n=s.size();
        long long cnt1=0;
        long long count0=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                cnt1++;
                
            }
            else count0+=cnt1;

        }
        return count0;
        
    }
};