class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        vector<string> new1;
        int c = 0;
        for(int i=0;i<m;i++){
            string k;
            for(int j=0;j<n;j++){
                k += strs[j][i];
            }
            string g = k;
            sort(k.begin(),k.end());
            if(k != g){
                c++;
            }
        } 
        return c;
    }
};