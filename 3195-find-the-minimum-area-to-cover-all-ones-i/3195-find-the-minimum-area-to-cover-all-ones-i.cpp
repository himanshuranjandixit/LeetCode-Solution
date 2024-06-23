class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int val1 = grid[0].size()-1 ;
        int val2 = 0;
        for(int i = 0; i<grid.size() ; i++){
            for(int j = 0 ; j<grid[i].size() ; j++){
                if(grid[i][j] ==1){
                    val1 = min(val1,j);
                    val2 = max(val2,j);
                }


            }
        }
        int breadth = val2 - val1 +1   ;
        vector<int>length ;
        for(int i = 0; i<grid.size() ; i++){
            for(int j = 0 ; j<grid[i].size() ; j++){
                if(grid[i][j] ==1){
                  length.emplace_back(i) ;
                   break;
                }
            }
        }
        sort(length.begin(),length.end()) ;
        int len = length[length.size()-1] - length[0] +1 ;
        return len * breadth ;

        
    }
};