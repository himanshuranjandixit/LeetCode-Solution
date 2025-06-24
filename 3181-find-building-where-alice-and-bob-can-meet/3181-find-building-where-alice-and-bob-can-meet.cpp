class Solution {
public:
    void buildTree(int i, int l, int r, int segTree[], vector<int>& heights){
        if(l==r){
            segTree[i] =l;
            return;
        }
        int mid = l+ (r-l)/2;
        buildTree(2*i+1,l,mid,segTree, heights);
        buildTree(2*i+2,mid+1,r,segTree,heights);
        int left_indx =segTree[2*i+1];
        int right_indx = segTree[2*i+2];
        if(heights[left_indx]>=heights[right_indx]) segTree[i] = left_indx;
        else segTree[i] = right_indx;
        
    }
    int *constructST(vector<int>& heights, int n){
        int * segTree = new int[4*n];
        buildTree(0,0,n-1,segTree,heights);
        return segTree;
    }

    int solve(int st[],vector<int>& heights,int n,int start, int end, int i,int l , int r ){
        if(r<start || l>end){
            return -1;
        }
        if(l>=start && r<=end){
            return st[i];
        }
        int mid = l + (r-l)/2;
        int left_indx = solve(st,heights,n,start,end,2*i+1,l,mid);
        int right_indx = solve(st,heights,n,start,end,2*i+2,mid+1,r);
        if(left_indx==-1) return right_indx;
        if(right_indx==-1) return left_indx;
        if(heights[left_indx]>=heights[right_indx]) return left_indx;
        else return right_indx;

    }
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        int *segTree = constructST(heights,n);
        vector<int>ans;
        for(auto it:queries){
            int i= min(it[0],it[1]);
            int j = max(it[0],it[1]);
            if(i==j){
                ans.push_back(i);
                continue;
            }
            if(heights[j]>heights[i]){
                ans.push_back(j);
                continue;
            }
            int low = j+1;
            int high = n-1;
            int indx=INT_MAX;
            while(low<=high){
                int mid = low + (high-low)/2;
                int idx = solve(segTree, heights, n, low, mid, 0, 0, n-1);

                if(idx!=-1 && heights[idx]>max(heights[i],heights[j])){
                    indx=min(indx,idx);
                    high=mid-1;
                }
                else low=mid+1;

            }
            if(indx==INT_MAX) ans.push_back(-1);
            else ans.push_back(indx);
        }
        return ans;
        
    }
};