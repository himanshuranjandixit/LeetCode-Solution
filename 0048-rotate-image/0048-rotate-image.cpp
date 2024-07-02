class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int a=0;
        int b=0;
        int n = matrix.size();
        vector<vector<int>>v(matrix);
        for(int i = 0; i<n ; i++){
            for(int j = 0 ; j<n;j++){
                matrix[j][n-i-1]=v[i][j];


            }
        }
        
    }
};