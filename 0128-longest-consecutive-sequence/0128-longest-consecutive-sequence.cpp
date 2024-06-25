class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int maxx=0;
        int count =0;
        if(nums.size() == 0) return 0;
        for(int i =1; i<nums.size() ; i++){
            if(nums[i-1] == nums[i]){
                continue;
            }
            if(nums[i-1]==(nums[i]-1)){
                count++;
            }
            else{
                maxx=max(maxx,count);
                count=0;

            } 
        }
        maxx=max(maxx,count) ;
        return maxx+1;
        
    }
};