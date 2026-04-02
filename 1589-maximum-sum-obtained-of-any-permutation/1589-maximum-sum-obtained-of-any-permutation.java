class Solution {
    public int maxSumRangeQuery(int[] nums, int[][] requests) {
        int n = nums.length;
        int M = 1000000007;
        int[] diff = new int[n];
        for(int[] r : requests){
            diff[r[0]] +=1;
            if(r[1] +1 <n) diff[r[1]+1] -=1;
        }
        for(int i=1;i<n;i++){
            diff[i] += diff[i-1];
        }
        Arrays.sort(diff);
        Arrays.sort(nums);
        long ans =0;
        for(int i=0;i<n;i++){
            ans = (ans + 1L*diff[i]*nums[i])%M;
        }
        return (int)ans;
        
    }
}