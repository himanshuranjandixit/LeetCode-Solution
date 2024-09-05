class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        vector<int>v(n);
        vector<int>vv;
        int avg=0;
        // if(mean==6){
        //     for(int i=0;i<rolls.size();i++){
        //         if(rolls[i]<6) return vv;
        //     }
        //     for(int i=0;i<n;i++){
        //         v.push_back(6);

        //     }
        //     return v;
        // }
        for(int i=0 ; i<rolls.size();i++){
            avg+=rolls[i];

        }
        int left = mean*(n+rolls.size()) -avg;
        if(left<=0 || n*6<left || n>left){
            return vv;
        }
        int num = left/n;
        if(num*n <left && num==6) return vv;
        for(int i=0;i<n;i++){
            v[i]=num;
        }
        left-=num*n;
        bool check=true;
        while(check){
            for(int i=0;i<n;i++){
                if(left==0){
                    check = false;
                    break;
                }
                if(v[i]<6){
                    v[i]++;
                    left--;
                }
            }
        }
        return v;
        
    }
};