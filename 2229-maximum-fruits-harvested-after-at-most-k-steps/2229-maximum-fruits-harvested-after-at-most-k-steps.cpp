class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int lastIdx = fruits[fruits.size()-1][0];
        vector<int> prefixSum(lastIdx+1,0);
        int left = 0;
        if(fruits[left][0] == 0) {
            prefixSum[0] = fruits[left][1];
            left++;
        }
        for(int i = 1 ; i <= lastIdx; i++){
            if(fruits[left][0] == i) {
                prefixSum[i] = fruits[left][1];
                left++;
            }
            prefixSum[i] += prefixSum[i-1];
        }
        int ans = 0;
        for(int i = 0 ; i <fruits.size(); i++){
            int distance = k,a = 0,b = 0;
            if(fruits[i][0]<=startPos){
                distance -= (startPos-fruits[i][0]);
                if(distance<0) continue;
                a = prefixSum[min(startPos,lastIdx)]; 
                if(i>0 && fruits[i][0]>0) a-= prefixSum[fruits[i][0]-1]; 
                distance -= (startPos-fruits[i][0]); 
                if(distance>0){
                    b = prefixSum[min(startPos+distance,lastIdx)]-prefixSum[min(startPos,lastIdx)];
                }
            }
            else{
                distance -= abs(fruits[i][0]-startPos); 
                if(distance<0) continue;
                a = prefixSum[fruits[i][0]];
                if(startPos>0) a-= prefixSum[startPos-1];
                distance -= abs(fruits[i][0]-startPos);
                if(distance>0){
                    b = prefixSum[max(startPos-1,0)];
                    if(startPos-distance>0) b-=prefixSum[startPos-distance-1];
                }
            }
            ans = max(a+b,ans);
        }
        return ans;
    }
};
