class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        string s(tasks.size() * n, '#');
        unordered_map<char,int>mpp;
        for(auto it : tasks){
            mpp[it]++;
        }
        priority_queue<int>pq;
        for(auto it :mpp){
            pq.push(it.second);

        }
        int ans=0;
        while(!pq.empty()){
            vector<int>temp;
            for(int i=1;i<=n+1;i++){
                if(!pq.empty()){
                    int freq = pq.top();
                    pq.pop();
                    freq--;
                    temp.push_back(freq);
                }
            }
            for(auto it :temp){
                if(it>0) pq.push(it);
            }
            if(pq.empty()) ans+=temp.size();
            else ans+=n+1;
        }
        return ans;
        
    }
};