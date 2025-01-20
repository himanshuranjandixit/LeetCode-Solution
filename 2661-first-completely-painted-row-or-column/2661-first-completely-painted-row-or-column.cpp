class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n=mat.size();
        int m =mat[0].size();
        vector<int>rows(n);
        vector<int>cols(m);
        unordered_map<int,pair<int,int>>mpp;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int val = mat[i][j];
                mpp[val]={i,j};
            }
        }
        for(int i=0;i<arr.size();i++){
            int val = arr[i];
            auto [row,col]= mpp[val];
            rows[row]++;
            cols[col]++;
            if(rows[row]==m || cols[col]==n) return i;
        }
        return -1;


        
    }
};