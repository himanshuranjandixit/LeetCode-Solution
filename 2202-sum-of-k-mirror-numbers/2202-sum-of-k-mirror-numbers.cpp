class Solution {
public:
    bool ispalindrom(string s){
        int i=0;int j= s.size()-1;
        while(i<=j){
            if(s[i]!=s[j]) return false;
            i++;j--;
        }
        return true;
    }
    string Basek(long long num, int k){
        if(num==0) return "0";
        string res = "";
        while(num>0){
            res+=num%k;
            num/=k;
        }
        return res;
    }
    long long kMirror(int k, int n) {
        long long sum =0;
        int l =1;
        while(n>0){
            int hf = (l+1)/2;
            int min = pow(10,hf-1);
            int max= pow(10,hf)-1;
            for(int num = min ; num<=max; num++){
                string fh = to_string(num);
                string sh = fh;
                reverse(sh.begin(),sh.end());
                string pal="";
                if(l%2==0)  pal = fh + sh;
                else pal = fh + sh.substr(1);
                long long pal_num = stoll(pal);
                string basek = Basek(pal_num,k);
                if(ispalindrom(basek)){
                    sum+=pal_num;
                    n--;
                    if(n==0) break;
                }

            }
            l++;
        }
        return sum;

        
    }
};