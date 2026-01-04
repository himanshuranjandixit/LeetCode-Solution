class Solution {
public:
    int sum(int num){
        int sum = 0;
        for(int i = 1 ; i*i<=num ; i++){
            if(num%i==0){
                if(i*i == num) {
                    sum = sum + i;
                }
                else {
                    sum = sum + i;
                    sum = sum +  num/i;
                }
            }
        }
        return sum;
    }
    int countfactor(int num){
        int count = 0;
        for(int i = 1 ; i*i<=num ; i++){
            if(num%i==0){
                if(i*i == num) count+=1;
                else count+=2;
            }
            if(count>4) break;
        }
        return count;
    }
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i<nums.size(); i++){
            if(countfactor(nums[i])==4){
                ans += sum(nums[i]);
            }
        }
        return ans;
    }
};