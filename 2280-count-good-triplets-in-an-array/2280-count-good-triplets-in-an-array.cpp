class Solution {
public:
    void update(int i, int l , int r, int idx, vector<long long>& segTree){
        if(l==r){
            segTree[i] =1;
            return;
        }
        int mid = l + (r-l)/2;
        if(idx<=mid){
            update(2*i+1,l,mid,idx,segTree);
        }
        else{
            update(2*i+2,mid+1,r,idx,segTree);
        }
        segTree[i] = segTree[2*i+1] + segTree[2*i+2];
    }
    long long query(int start, int end, int i, int l , int r, vector<long long>& segTree){
        if(r<start || l>end) return 0;
        if(l>=start && r<=end) return segTree[i];
        int mid = l + (r-l)/2;
        long long left = query(start, end, 2*i+1, l, mid, segTree);
        long long right = query(start, end, 2*i+2, mid+1, r, segTree);
        return left+right;
    }
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        unordered_map<int,int>mpp;
        for(int i=0;i<n ;i++){
            mpp[nums2[i]] =i;
        }
        vector<long long>segTree(4*n,0);
        update(0,0,n-1,mpp[nums1[0]] ,segTree);
        long long ans =0;
        for(int i=1;i<n ;i++){
            int idx = mpp[nums1[i]];
            long long left_common = query(0,idx,0,0,n-1,segTree);
            long long left_uncommon = i-left_common;
            long long right_common = (n-1) -idx - left_uncommon;
            ans += left_common*right_common;
            update(0,0,n-1,idx,segTree);
        }
        return ans;
        
    }
};