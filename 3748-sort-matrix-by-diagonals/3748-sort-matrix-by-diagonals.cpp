class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>ans(n,vector<int>(m));
        for(int i = m-1; i>=0;i--){
            int row = 0;
            int col = i;
            vector<int>temp;
            while(row<n && col<m){
                temp.push_back(grid[row][col]);
                row++;
                col++;
            }
            if(i!=m){
                vector<int>temp;
                int row = n-1;
                int col = i;
                while(row>=0 && col>=0){
                    temp.push_back(grid[row][col]);
                    row--;
                    col--;
                }
                sort(temp.begin(),temp.end());
                row = n-1;
                col = i;
                int indx =0;
                while(row>=0 && col>=0){
                    ans[row][col]=temp[indx];
                    row--;
                    col--;
                    indx++;
                }
            }
            if(i==0) continue;
            sort(temp.begin(),temp.end());
            row=0;
            col=i;
            int indx =0;
            while(row<n && col<m){
                ans[row][col] =temp[indx];
                row++;
                col++;
                indx++;
            }
        }
        return ans;
        
    }
};