class Solution {
public:
    int parent[100005] = {0};
    int find(int day) {
        // if (day > 100000) return day; 
        if(parent[day] == 0) return day; 
        return parent[day] = find(parent[day]); 
    }

    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int res = 0;

        for(auto& e : events){
            int day = find(e[0]); 
            if(day <= e[1]){    
                parent[day] = day + 1;
                res++;
            }
        }

        return res;
    }
};