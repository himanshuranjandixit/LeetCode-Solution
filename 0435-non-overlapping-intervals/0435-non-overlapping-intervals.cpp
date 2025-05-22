class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int count=0;
        sort(intervals.begin(),intervals.end(),[](const vector<int>& a, vector<int>& b){
            return a[1]<b[1];
        });
        int start= intervals[0][0];
        int end=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<end){
                count++;
                continue;
            }
            start=intervals[i][0];
            end=intervals[i][1];
        }
        return count ;
        
    }
};