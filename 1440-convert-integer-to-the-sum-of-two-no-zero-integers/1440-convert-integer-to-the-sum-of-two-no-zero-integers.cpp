class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        int a, b, m;
    for(int i=1;i<n;i++){
        a=i;
        m=a;
        while(m!=0){
            if(m%10==0){
                a=m;
                break;
            }
            m=m/10;
        }
        if(a%10==0)
             continue;

        b=n-i;
        m=b;
        while(m!=0){
            if(m%10==0){
                b=m;
                break;
            }  
            m=m/10;
        }
        if(b%10==0)
            continue;
        if(a+b==n){
          return {a,b};
        }
       }  
       return {};
    }
};