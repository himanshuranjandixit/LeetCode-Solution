class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<int> gaps;
        vector<pair<int, int>> events;
        for (int i = 0; i < n; i++) {
            events.push_back({startTime[i], endTime[i]});
        }
        if(events[0].first > 0){
            gaps.push_back(events[0].first);
        }
        for(int i = 1; i < n; i++){
            int gap = events[i].first - events[i - 1].second;
            gaps.push_back(gap);
        }
        if(events.back().second < eventTime){
            gaps.push_back(eventTime - events.back().second);
        }

        int maxFree = 0, currSum = 0;
        int windowSize = k + 1;
        if(gaps.size() < windowSize){
            for(int g : gaps) currSum += g;
            return currSum;
        }

        for (int i = 0; i < windowSize; i++) {
            currSum += gaps[i];
        }
        maxFree = currSum;
        for (int i = windowSize;i < gaps.size();i++) {
            currSum += gaps[i] - gaps[i - windowSize];
            maxFree = max(maxFree, currSum);
        }
        return maxFree;
    }
};
