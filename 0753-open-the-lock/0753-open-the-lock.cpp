class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        priority_queue<pair<int,string>,vector<pair<int,string>>,greater<>>pq;
        pq.push({0,"0000"});
        unordered_map<string,bool>mpp;
        for(auto it :deadends){
            mpp[it]=true;
        }
        if(mpp.count("0000")) return -1;
        vector<char>v={'0','1','2','3','4','5','6','7','8','9'};
        mpp["0000"]=true;
        while(!pq.empty()){
            int count = pq.top().first;
            string node = pq.top().second;
            pq.pop();
            if(node == target) return count;
            for(int i=0;i<4;i++){
                for(int j=0;j<4;j++){
                    char org = node[j];
                    node[j]=v[(org-'0'+1)%10];
                    if(!mpp.count(node)){
                        pq.push({count+1,node});
                        mpp[node]=true;
                    }
                    node[j] = v[(org-'0'+9)%10];
                    if(!mpp.count(node)){
                        pq.push({count+1,node});
                        mpp[node]=true;
                    }
                    node[j]=org;
                }

            }
        }
        return -1;

        
    }
};