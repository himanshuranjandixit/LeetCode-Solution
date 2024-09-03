class Solution {
public:
    int getLucky(string s, int k) {
        string v;
        for(int i=0;i<s.size();i++){
            int n=(int)(s[i])-96;
            if(n<10) v.push_back(n);
            else {
                v.push_back(n%10);
                n/=10;
                v.push_back(n);
            }
        }
        k--;
        int sum=0;
        for(auto i : v){
            sum+=i;
        }
        while(k>0){
            int num=0;
            while(sum>0){
                num+=sum%10;
                sum/=10;
            }
            sum=num;
            k--;
        }
        return sum;

        
    }
};