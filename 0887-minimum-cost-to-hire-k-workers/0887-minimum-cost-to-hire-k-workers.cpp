class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        vector<pair<int,int>>v;
        for(int i=0;i<wage.size();i++){
            v.push_back({wage[i],quality[i]});
        }
        sort(v.begin(),v.end(),[](const pair<int,int>&a, const pair<int,int>&b){
            return a.second<b.second;
        });
        double ans = 1e18;
        for(int i = 0 ;i<v.size();i++){
            int wage_ = v[i].first;
            int quality_ = v[i].second;
            double ratio =(double) wage_/quality_;
            int num = k-1;
            double val =wage_;
            for(int j=0;j<v.size();j++){
                if(i==j) continue;
                if(v[j].second*ratio >= v[j].first && num>0){
                    val +=v[j].second*ratio;
                    num--;
                }
            }
            if(!num) ans=min(ans,val);
        }
        return ans;
        
    }
};