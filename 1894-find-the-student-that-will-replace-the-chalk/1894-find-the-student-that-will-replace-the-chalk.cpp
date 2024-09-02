class Solution {
public:
    int chalkReplacer(vector<int>& chalk,long long int k) {
        int ans;
        long long int sum=0;
        for(int i=0;i<chalk.size();i++){
            sum+=chalk[i];
        }
        k%=sum;
        if(k==0) return 0;
        while(k>0){
            for(int i=0;i<chalk.size();i++){
                k-=chalk[i];
                ans=i;
                if(k<=0) break;
            }
        }
        if(k==0 && ans ==chalk.size()-1) return 0;
        if(k==0) return ans+1;
        return ans;




        
    }
};