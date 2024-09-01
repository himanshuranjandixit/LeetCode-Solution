class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>>v(m,vector<int>(n));
        vector<vector<int>>vv;
        if(m*n!=original.size()) return vv;
        int check =0;
        int k=0;
        int j=0;
        for(int i=0;i<original.size();i++){
            v[k][j]=original[i];
            check++;
            j++;
            if(check==n){
                k++;
                check=0;
                j=0;
            }
        }
        return v;
    }
};