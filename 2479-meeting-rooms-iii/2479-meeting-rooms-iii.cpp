class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        vector<long long>v(n, 0);

        priority_queue<int,vector<int>,greater<>>freeRooms;
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<>>pq; // {endTime, roomNo}
        for(int i = 0; i < n; ++i){
            freeRooms.push(i);
        }
        for(int i = 0;i<meetings.size();i++){
            long long start = meetings[i][0];
            long long end = meetings[i][1];
            while(!pq.empty() && pq.top().first <= start) {
                freeRooms.push(pq.top().second);
                pq.pop();
            }

            if(!freeRooms.empty()){
                int roomNo = freeRooms.top();
                freeRooms.pop();
                v[roomNo]++;
                pq.push({end, roomNo});
            }
            else{
                auto [endTime, roomNo] = pq.top();
                pq.pop();
                v[roomNo]++;
                long long newEndTime = endTime + (end - start);
                pq.push({newEndTime, roomNo});
            }
        }
        int ans = 0;
        for (int i = 1; i < n; ++i) {
            if(v[i] > v[ans]) ans = i;
        }
        return ans;
    }
};
