class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int count=0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int it=0;
        for(int i=0;i<g.size();i++){
            int num = g[i];
            while(it<s.size()){
                if(num<=s[it]){
                    count++;
                    break;
                }
                it++;
            }
        }
        return count;
        
    }
};