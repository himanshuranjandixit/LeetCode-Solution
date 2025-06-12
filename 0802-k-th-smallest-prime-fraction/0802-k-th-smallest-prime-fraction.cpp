class Solution {
public:
    typedef pair<double, pair<int, int>> p;
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<p>pq;
        for(int i=0;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                double fraction = (double)arr[i]/arr[j];
                if(pq.size()<k) pq.push({fraction,{arr[i],arr[j]}});
                else{
                    if(fraction<pq.top().first){
                        pq.pop();
                        pq.push({fraction,{arr[i],arr[j]}});
                    }
                }
            }
        }
        vector<int>ans;
        ans.push_back(pq.top().second.first);
        ans.push_back(pq.top().second.second);
        return ans;
    }
};