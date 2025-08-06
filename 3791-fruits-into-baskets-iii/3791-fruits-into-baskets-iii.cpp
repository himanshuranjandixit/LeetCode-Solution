class Solution {
public:
    bool query(vector<int>& segTree, int indx, int left, int right,int target){
        if(segTree[indx]<target) return false;
        if(left == right){
            segTree[indx]=-1;
            return true;
        }
        int mid =left + (right - left)/2;
        bool flag =false ;
        if(segTree[2*indx+1]>=target){
            flag = query(segTree,2*indx+1,left,mid,target);
        }
        else{
            flag = query(segTree,2*indx+2,mid+1,right,target);
        }
        segTree[indx] = max(segTree[2*indx+1],segTree[2*indx+2]);
        return flag;
    }
    void buildTree(vector<int>& segTree, vector<int>& baskets, int indx, int left, int right){
        if(left==right){
            segTree[indx] = baskets[left];
            return;
        }
        int mid = left + (right - left)/2;
        buildTree(segTree,baskets,2*indx+1,left,mid);
        buildTree(segTree,baskets,2*indx+2,mid+1,right);
        segTree[indx] = max(segTree[2*indx+1],segTree[2*indx+2]);
    }
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = baskets.size();
        vector<int>segTree(4*n,-1);
        buildTree(segTree,baskets,0,0,n-1);
        int ans=0;
        for(int i=0;i<fruits.size();i++){
            if(!query(segTree,0,0,n-1,fruits[i])) ans++;
        }
        return ans;
        
    }
};