class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int>for_i ;
        set<int>for_j ;
        for(int i = 0 ; i<matrix.size() ; i++){
            for(int j = 0 ; j<matrix[i].size() ; j++){
                if(matrix[i][j] == 0){
                    for_i.insert(i);
                    for_j.insert(j);
                }

            }
        }
        for(auto it :for_i){
            for(int i = 0 ; i<matrix[it].size() ; i++){
                matrix[it][i] = 0;
            }
        }
        for(auto it1 : for_j){
            for(int i = 0 ; i<matrix.size() ; i++){
                matrix[i][it1] = 0;
            }
        }
        
        
        
    }
};