class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>>v;
        for(int i=0;i<capital.size();i++){
            v.push_back({capital[i],profits[i]});
        }
        sort(v.begin(),v.end());
        int indx =0;
        priority_queue<int>pq;
        while(k>0){
            while(indx<v.size() && w>=v[indx].first){
                pq.push(v[indx].second);
                indx++;
            }
            if(pq.empty()) break;
            w+=pq.top();
            pq.pop();
            k--;
        }
        return w;
        
    }
};