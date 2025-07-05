class Solution {
public:
    void buildSegmentTree(int i, int l, int r, vector<int>& segmentTree,vector<int>& arr) {
        if(l == r) { // reached at leaf node
            segmentTree[i] = arr[l];
            return;
        }
        
        int mid = l + (r-l)/2;
        buildSegmentTree(2*i+1, l, mid, segmentTree, arr); // creating left child
        buildSegmentTree(2*i+2, mid+1, r, segmentTree, arr); // creating right child
        segmentTree[i] = max(segmentTree[2*i + 1],segmentTree[2*i + 2]);
    }
    int querySegmentTree(int start, int end, int i, int l, int r, vector<int>& segmentTree) {
        if(l > end || r < start){ // range is out of bound
            return INT_MIN;
        }
        
        if(l >= start && r <= end) {  // overlapping complete range
            return segmentTree[i];
        }
        
        int mid = l + (r-l)/2;
        return max(querySegmentTree(start, end, 2*i+1, l,mid,segmentTree),querySegmentTree(start, end, 2*i+2, mid+1, r, segmentTree));
    }
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>segmentTree(4*n);
        buildSegmentTree(0,0,n-1,segmentTree,nums);
        vector<int>ans;
        for(int i=0;i<n;i++){
            int start = i;
            int end = i+k-1;
            if(i+k-1==n) break;
            
            int val = querySegmentTree(start,end,0,0,n-1,segmentTree);
            ans.push_back(val); 
        }
        return ans;
       
    }
};