class NumArray {
public:
    vector<int>segTree;
    int N;
    void buildTree(int indx, int l, int r, vector<int>& nums){
        if(l==r){
            segTree[indx] = nums[r];
            return;
        }
        int mid = l + (r-l)/2;
        buildTree(2*indx+1,l,mid,nums);
        buildTree(2*indx+2,mid+1,r,nums);
        segTree[indx] = segTree[2*indx+1] + segTree[2*indx+2];
    }
    NumArray(vector<int>& nums) {
        N=nums.size();
        segTree.resize(4*nums.size());
        buildTree(0,0,nums.size()-1,nums);
    }
    
    void updateSegTree(int indx, int val, int i, int l, int r){
        if(l==r){
            segTree[i]=val;
            return;
        }
        int mid = l+ (r-l)/2;
        if(indx<=mid) updateSegTree(indx,val,2*i+1,l,mid);
        else updateSegTree(indx,val,2*i+2,mid+1,r);
        segTree[i] = segTree[2*i+1] + segTree[2*i+2];
    }

    void update(int index, int val) {
        updateSegTree(index,val,0,0,N-1);
        
    }
    
    int solve(int left, int right,int i, int l, int r){
        if(l>right || r<left) return 0;
        if(l>=left && r<=right) return segTree[i];
        int mid =l + (r-l)/2;
        return solve(left,right,2*i+1,l,mid) + solve(left,right,2*i+2,mid+1,r);
    }

    int sumRange(int left, int right) {
        return solve(left,right,0,0,N-1);
        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */