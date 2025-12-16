class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string ans="";
        if(1LL*numerator*denominator<0) ans+='-';
        long long num = labs(numerator);
        long long deno = labs(denominator);
        long long val = num/deno;
        long long remainder = num%deno;
        ans+=to_string(val);
        if(remainder==0) return ans;
        ans+='.';
        unordered_map<long long,int>mpp;
        while(remainder!=0){
            if(mpp.count(remainder)){
                ans.insert(mpp[remainder],"(");
                ans+=')';
                break;
            }
            mpp[remainder]=ans.size();
            remainder*=10;
            val= remainder/deno;
            ans+=to_string(val);
            remainder=remainder%deno;
        }
        return ans;

    }
};