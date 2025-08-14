class Solution {
public:
    string largestGoodInteger(string num) {
        string ans="";
        int l=0;
        int cnt=0;
        while(l<num.size()-1){
            if(num[l]==num[l+1]){
                cnt++;
                if(cnt==2){
                    if(ans.empty()) ans=num[l];
                    else if(ans[0]<num[l]){
                        ans=num[l];
                    }
                }
            }
            else cnt=0;
            l++;
        }
        if(ans.empty()) return ans;
        for(int i=0;i<2;i++) ans+=ans[0];
        return ans;
        
    }
};