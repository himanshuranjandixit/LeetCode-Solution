class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>>v;
        for(int i=0;i<nums1.size();i++){
            v.push_back({nums1[i],nums2[i]});
        }
        sort(v.begin(),v.end(),[](const pair<int,int>& a, const pair<int,int>& b){
            return a.second>b.second;
        });
        priority_queue<int,vector<int>,greater<int>>pq;
        long long ksum = 0;
        for(int i=0;i<k;i++){
            ksum+=v[i].first;
            pq.push(v[i].first);
        }
        long long ans=ksum*v[k-1].second;
        for(int i=k;i<v.size();i++){
            ksum+=v[i].first - pq.top();
            pq.pop();
            ans=max(ans,ksum*v[i].second);
            pq.push(v[i].first);
        }
        return ans;

    }

};