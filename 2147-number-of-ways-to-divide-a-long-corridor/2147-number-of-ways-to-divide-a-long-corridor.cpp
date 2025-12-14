class Solution {
public:
    int m = 1e9+7;
    int numberOfWays(string corridor) {
        vector<int>v;
        for(int i=0;i<corridor.size();i++){
            if(corridor[i]=='S') v.push_back(i);
        }
        if(v.size()%2!=0 || v.size()==0) return 0;
        long long ans=1;
        for(int i=1;i<v.size()-1;i+=2){
            ans=(ans*(v[i+1]-v[i]))%m;
        }
        return (int)ans;
        
    }
};