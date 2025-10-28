class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                for(int dir = -1; dir <= 1; dir += 2){  // -1 for left, 1 for right
                    vector<int> num = nums;
                    int curr = i;
                    int currentDir = dir;
                    
                    // Move one step initially
                    curr += currentDir;
                    
                    while(curr >= 0 && curr < num.size()){
                        if(num[curr] == 0){
                            // Empty cell, keep moving
                            curr += currentDir;
                        } else {
                            // Hit a non-zero, decrement and bounce
                            num[curr]--;
                            currentDir = -currentDir;  // Reverse direction
                            curr += currentDir;  // Move in new direction
                        }
                    }
                    
                    // Check if all elements are zero
                    bool allZero = true;
                    for(int val : num){
                        if(val != 0){
                            allZero = false;
                            break;
                        }
                    }
                    
                    if(allZero){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};