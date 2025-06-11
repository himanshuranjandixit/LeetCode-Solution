class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        for(auto it : stones) pq.push(it);
        while(pq.size()>1){
            int stone1 =pq.top();
            pq.pop();
            int stone2 = pq.top();
            pq.pop();
            int val = abs(stone1-stone2);
            if(val!=0) pq.push(val);
        }
        if(!pq.empty()) return pq.top();
        return 0;
        
    }
};