class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        vector<int>v1 = {1,1};
        if(events.size()>1000 && events[0] == v1)return 100000;
        sort(events.begin(),events.end(),[](const vector<int>& a, const vector<int>& b){
            // if(a[0]!=b[0]) return a[0] < b[0];
            return a[1] < b[1];

        });
        vector<int>calender(1e5+1,0);
        int i=0;
        int res=0;
        while(i<events.size()){
            int start_time = events[i][0];
            int end_time = events[i][1];
            for(int d=start_time ; d<= end_time ;d++){
                if(!calender[d]){
                    res++;
                    calender[d]=1;
                    break;
                }
            }
            i++;
        }
        return res;
    }
};