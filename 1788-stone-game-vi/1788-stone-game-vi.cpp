class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<aliceValues.size();i++){
            int val = aliceValues[i] + bobValues[i];
            pq.push({val,i});
        }
        vector<int>stone(2,0);
        int turn=0;
        while(!pq.empty()){
            int indx = pq.top().second;
            stone[turn] += ((turn%2==0) ? aliceValues[indx] : bobValues[indx]);
            turn^=1;
            pq.pop();

        }
        if(stone[0]>stone[1]) return 1;
        if(stone[0]<stone[1]) return -1;
        return 0;
        

        
    }
};