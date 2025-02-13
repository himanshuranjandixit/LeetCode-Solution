class Solution {
public:
    void solve(vector<vector<char>>& board) {
        vector<vector<int>>vis(board.size(),vector<int>(board[0].size(),0));
        queue<pair<int,int>>q;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
               if(i==0 && board[i][j]=='O'){
                    q.push({i,j});
                    vis[i][j]=1;
                }
                if(j==0 && board[i][j]=='O'){
                    q.push({i,j});
                    vis[i][j]=1;
                }
                if(i==board.size()-1 && board[i][j]=='O'){
                    q.push({i,j});
                    vis[i][j]=1;
                }
                if(j==board[0].size()-1 && board[i][j]=='O'){
                    q.push({i,j});
                    vis[i][j]=1;
                }

            }
        }
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            board[i][j]='1';
            q.pop();
            int drow[4]={-1,0,1,0};
            int dcol[4]={0,1,0,-1};
            for(int k=0;k<4;k++){
                int row=i+drow[k];
                int col=j+dcol[k]; 
                if(row>=0 && row<board.size() && col>=0 && col<board[0].size() && vis[row][col]==0 && board[row][col]=='O'){
                    vis[row][col]=1;
                    q.push({row,col});
                }
            }
        }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='O') board[i][j]='X';
                else if(board[i][j]=='1') board[i][j]='O';
            }
        }  
    }
};