class Solution {
public:
    void buildSegmentTree(int i, int l, int r, vector<pair<int,int>> &v, vector<int> &nums){
        if(l==r){
            v[i]={nums[l],nums[r]};
            return;
        }
        int mid = l + (r-l)/2;
        buildSegmentTree(2*i+1,l,mid,v,nums);
        buildSegmentTree(2*i+2,mid+1,r,v,nums);
        v[i].first = max(v[2*i+1].first,v[2*i+2].first);
        v[i].second = min(v[2*i+1].second,v[2*i+2].second);
    }
    int Max(int i, int l, int r, int left, int right, vector<pair<int,int>> &v){
        if(left>r || right <l) return INT_MIN;
        if(left<=l && right>=r) return v[i].first;
        int mid = l + (r-l)/2;
        return max(Max(2*i+1,l,mid,left,right,v),Max(2*i+2,mid+1,r,left,right,v));

    }
    int Min(int i, int l, int r, int left, int right, vector<pair<int,int>> &v){
        if(left>r || right <l) return INT_MAX;
        if(left<=l && right>=r) return v[i].second;
        int mid = l + (r-l)/2;
        return min(Min(2*i+1,l,mid,left,right,v),Min(2*i+2,mid+1,r,left,right,v));

    }
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<int,int>>v(4*n);
        buildSegmentTree(0,0,n-1,v,nums);
        priority_queue<pair<int,pair<int,int>>>pq;
        int maxi = Max(0,0,n-1,0,n-1,v);
        int mini = Min(0,0,n-1,0,n-1,v);
        int val = maxi-mini;
        pq.push({val,{0,n-1}});
        long long ans=0;
        set<pair<int,int>>st;
        st.insert({0,n-1});
        while(k-- && !pq.empty()){
            int val = pq.top().first;
            int l = pq.top().second.first;
            int r = pq.top().second.second;
            pq.pop();
            ans+=val;
            if (l + 1 <= r && !st.count({l + 1, r})){
                st.insert({l+1,r});
                int val1 = Max(0,0,n-1,l+1,r,v) - Min(0,0, n-1,l+1,r,v);
                pq.push({val1,{l+1,r}});
            }
            if (l <= r - 1 && !st.count({l, r - 1})){
                st.insert({l,r-1});
                int val2 = Max(0,0,n-1,l,r-1,v) - Min(0,0, n-1,l,r-1,v);
                pq.push({val2,{l,r-1}});
            }
        }
        return ans;



        
    }
};