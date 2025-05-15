class Solution {
public:
    int myAtoi(string s) {
        int i=0;long ans=0;int sign=1;
        while(i<s.size() && s[i]==' ')i++;
        if(s[i]=='-'){
            sign=-1;
            i++;
        }
        else if(s[i]=='+') i++;
        
        if(!isdigit(s[i])) return 0;
        int base=1;
        while(i<s.size() && isdigit(s[i])){
            ans = ans*10 + (s[i]-'0');
            if(ans*sign>INT_MAX) return INT_MAX;
            if(ans*sign<INT_MIN) return INT_MIN;
            i++;
        }
        return (int)(ans*sign);
    }
};