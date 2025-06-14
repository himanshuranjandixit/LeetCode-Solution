class Solution {
public:
    int minMaxDifference(int num) {
        string num1 = to_string(num);
        char chmax ='0';
        char chmin='0';
        for(auto it:num1){
            if(it!='9'){
                chmax =it;
                break;
            }

        }
        for(auto it:num1){
            if(it!='0'){
                chmin =it;
                break;
            }

        }
        string maxi="";
        string mini="";
        for(auto it : num1){
            if(it==chmax) maxi +='9';
            else maxi+=it;
            if(it==chmin) mini+='0';
            else mini+=it;
        }
        int ans =stoi(maxi)-stoi(mini);
        return ans;

        
    }
};