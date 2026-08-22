class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>>ans;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>>pq;
        int sum = nums1[0] + nums2[0];
        pq.push({sum,{0,0}});
        set<pair<int,int>>st;
        st.insert({0,0});
        while(k--&& !pq.empty()){
            int sum = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            cout<<i<<" "<<j<<" "<<sum<<endl;
            pq.pop();
            ans.push_back({nums1[i],nums2[j]});
            if(j+1<nums2.size() && !st.count({i,j+1})){
                pq.push({nums1[i] + nums2[j+1],{i,j+1}});
                st.insert({i,j+1});
            }
            if(i+1<nums1.size() && !st.count({i+1,j})){
                pq.push({nums1[i+1] + nums2[j],{i+1,j}});
                st.insert({i+1,j});
            }
        }
        return ans;
    }
};