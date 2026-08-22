class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int,pair<int,int>>>pq;
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                if(pq.size()==k){
                    if(nums1[i]+nums2[j]>=pq.top().first)break;
                    else{
                        pq.pop();
                    }
                }
                pq.push(make_pair(nums1[i]+nums2[j],make_pair(nums1[i],nums2[j])));
            }
        }
        vector<vector<int>>ans;
        while(k--){
            auto it = pq.top();
            pq.pop();
            vector<int>temp;
            temp.push_back(it.second.first);
            temp.push_back(it.second.second);
            ans.push_back(temp);
        }
        return ans;
        
    }
};