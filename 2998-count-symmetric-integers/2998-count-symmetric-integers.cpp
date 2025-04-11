class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans=0;
        for(int i=low ;i<=high;i++){
            string s=to_string(i);
            if(s.size()%2!=0) continue;
            int n = s.size();
            int left=0;
            int right=0;
            for(int j=0;j<n;j++){
                if(j<n/2) left+=(int)(s[j]);
                else right+=(int)(s[j]);
            }
            if(left==right) ans++;
        }
        return ans;

        
    }
};