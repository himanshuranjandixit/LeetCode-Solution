class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int>mpp;
        for(auto it : s){
            mpp[it]++;
        }
        priority_queue<pair<int,char>>pq;
        for(auto it :mpp){
            pq.push({it.second,it.first});
        }
        pair<int,char> prev={0,'$'};
        string ans ="";
        while(!pq.empty()){
            auto it = pq.top();
            int count = it.first;
            pq.pop();
            ans+=it.second;
            if(prev.first>0){
                pq.push(prev);
            }
            count--;
            prev={count,it.second};
        } 
        if(ans.size()<s.size()) return "";
        for(int i=0;i<ans.size()-1;i++){
            if(ans[i]==ans[i+1]) return "";
        }
        return ans;

    }
};