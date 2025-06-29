class Solution {
public:
    string decimal2binary(int num){
        string ans="";
        while(num>0){
            ans += num%2 + '0';
            num /= 2;
        }
        for(int i= ans.size();i<32;i++){
            ans+='0';
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    int minFlips(int a, int b, int c) {
        string binaryofa = decimal2binary(a);
        string binaryofb = decimal2binary(b);
        string binaryofc = decimal2binary(c);
        int flip=0;
        for(int i=0;i<32;i++){
            int chofa = binaryofa[i] - '0';
            int chofb = binaryofb[i] - '0';
            int chofc = binaryofc[i] - '0';
            if((chofa | chofb) == chofc) continue;
            if(chofc==0){
                if (chofa == 1) flip++;
                if (chofb == 1) flip++;
            }
            else{
                if(chofa == 0 && chofb == 0 ) flip++;
            }
        }
        return flip;


        
    }
};