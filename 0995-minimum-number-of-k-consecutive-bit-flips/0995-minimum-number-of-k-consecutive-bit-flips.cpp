class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int count = 0;

        for(int i = 0 ; i< nums.size() ; i++){
            if(nums[i] == 0 && i+k <= nums.size()){
                count++;
                for(int j = 0 ; j<k ; j++){
                    nums[i+j]^=1 ;
                }
            }
        }
        
        for(int i = 0 ; i< nums.size() ; i++){
          if(nums[i] == 0) return -1 ;
        }
       
       return count ;
    }
};