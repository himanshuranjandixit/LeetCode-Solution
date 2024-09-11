class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans=0;
        ans=start^goal;
        int cnt=0;
        while(ans!=0){
            if(ans%2!=0) cnt++;
            ans/=2;
        }
        return cnt;
        
    }
};