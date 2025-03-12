class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n=nums.size();
        int l=-1;
        int r=-1;
        int pos=-1;
        for(int i=0;i<n;i++){
            if(nums[i]==0 && l==-1) l=i;
            if(nums[i]==0 && l!=-1) r=i;
            if(nums[i]>0){
                pos=i;
                break;
            }
                
        }
        if(l!=-1 && r!=-1) return max(l,n-r-1);
        if(l!=-1 && r==-1) return max(l,n-l-1);
        if(l==-1 && r==-1 && pos!=-1) return max(pos,n-pos);
        return n;
        
    }
};