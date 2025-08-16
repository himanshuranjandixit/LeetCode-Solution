class Solution {
public:
    int maximum69Number (int num) {
        string n = to_string(num);
        for(int i=0;i<n.size();i++){
            if(n[i]=='6'){
                n[i]='9';
                break;
            }
        }
        int ans=0;
        for(auto it :n){
            ans = ans*10 + int(it)-'0';
        }
        return ans;
        
    }
};