class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int,int>mpp;
        unordered_map<int,int>mpp1;
        unordered_map<int,int>mpp2;
        int mini=INT_MAX;
        for(auto it :basket1){
            mpp[it]++;
            mpp1[it]++;
            mini=min(mini,it);
        }
        for(auto it:basket2){
            mpp[it]++;
            mpp2[it]++;
            mini=min(mini,it);
        }
        for(auto it : mpp){
            if(it.second%2!=0) return -1;
        }
        vector<int>v1,v2;
        for(auto it :mpp){
            int count = it.second;
            int val = it.first;
            if(mpp1[val] == count/2){
                continue;
            }
            if(mpp1[val]>count/2){
                int req = mpp1[val] - count/2;
                while(req--){
                    v1.push_back(val);
                }
            }

        }
        for(auto it :mpp){
            int count = it.second;
            int val = it.first;
            if(mpp2[val] == count/2){
                continue;
            }
            if(mpp2[val]>count/2){
                int req = mpp2[val] - count/2;
                while(req--){
                    v2.push_back(val);
                }
            }
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end(),greater<int>());
        long long ans=0;
        for(int i=0;i<v1.size();i++){
            ans += min(2*mini,min(v1[i],v2[i]));

        }
        return ans;
    }
};