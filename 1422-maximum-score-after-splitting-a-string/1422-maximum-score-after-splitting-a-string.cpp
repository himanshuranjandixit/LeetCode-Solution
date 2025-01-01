class Solution {
public:
    int maxScore(string s) {
        int sum=0;
        for(auto it : s){
            sum+=it-48;
        }
        if(sum==0){
            return s.size()-1;
        }

        int ans=0;
        int cnt=0;
        for(auto it : s){
            if (it=='0'){
                cnt++;
                ans=max(ans,sum+cnt);
                
            }
            else{
                sum--;
                ans=max(ans,sum+cnt);
            }
        }

        return ans;
        
    }
};