class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>pq;
        for(auto it:piles){
            pq.push(it);
        }
        while(k!=0){
            int val =pq.top();
            pq.pop();
            val=ceil(val/2.0);
            pq.push(val);
            k--;
        }
        int ans=0;
        while(!pq.empty()){
            ans+=pq.top();
            pq.pop();

        }
        return ans;
        
    }
};