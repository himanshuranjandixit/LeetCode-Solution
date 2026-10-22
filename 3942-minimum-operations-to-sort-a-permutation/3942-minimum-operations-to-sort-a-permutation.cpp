class Solution {
public:
    bool issorted(vector<int>&v){
        for(int i=0;i<v.size()-1;i++){
            if(v[i]>v[i+1]) return false;
        }
        return true;
    }
    int minOperations(vector<int>& nums) {
        if(issorted(nums)) return 0;
        int zero = find(nums.begin(),nums.end(),0)- nums.begin();
        int asc = true;
        int dsc = true;
        int n = nums.size();
        for(int i=1;i<nums.size();i++){
            int val = nums[(zero+i)%n];
            if(val!=i) asc = false;
            if(val != n-i) dsc= false;
            if(!dsc && !asc) return -1;
        }
        if(asc){
            return min(zero,n-zero+2);
        }
        return min(zero+2,n-zero);

    }
};