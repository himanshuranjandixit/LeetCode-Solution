class Solution {
public:
    string removeDigit(string number, char digit) {
        string ans="";
        for(int i=0;i<number.size();i++){
            if(number[i]==digit){
                if(ans=="") ans+= number.substr(0,i) + number.substr(i+1);
                else{
                    string temp = number.substr(0,i) + number.substr(i+1);
                    if(temp>ans) ans = temp;
                }
            }
        }
        return ans;
        
    }
};