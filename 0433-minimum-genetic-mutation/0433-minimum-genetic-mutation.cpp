class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        if(startGene==endGene) return 0;
        set<string>st;
        for(auto it : bank){
            st.insert(it);
        }
        priority_queue<pair<int,string>,vector<pair<int,string>>,greater<>>pq;
        pq.push({0,startGene});
        char arr[4]={'A','C','G','T'};
        
        while(!pq.empty()){
            int step = pq.top().first;
            string gene = pq.top().second;
            pq.pop();
            if(gene==endGene) return step;
            for(int i=0;i<gene.size();i++){
                char ch = gene[i];
                for(int j=0;j<4;j++){
                    gene[i]= arr[j];
                    if(st.find(gene)!=st.end()){
                        pq.push({step+1,gene});
                        st.erase(gene);
                    }
                }
                gene[i]=ch;
            }
        }
        return -1;

        
    }
};