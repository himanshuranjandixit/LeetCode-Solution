class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        int curr_row = 0 ;
        int curr_col = 0;
        vector<int> res;
        bool goingup = true;
        while(res.size()<(rows * cols)){
            if(goingup){
                while(curr_row >= 0 && curr_col < cols){
                    res.push_back(mat[curr_row][curr_col]);
                    curr_row -= 1;
                    curr_col += 1;
                }
                if(curr_col == cols){
                    curr_col -= 1;
                    curr_row += 2;
                }
                else curr_row += 1;
                goingup = false;
            }
            else{
                while(curr_row < rows && curr_col >= 0){
                    res.push_back(mat[curr_row][curr_col]);
                    curr_row += 1;
                    curr_col -= 1;
                }
                if(curr_row == rows){
                    curr_row -= 1;
                    curr_col += 2;
                }
                else curr_col += 1;
                goingup = true;
            }
        }
        return res;
    }
};