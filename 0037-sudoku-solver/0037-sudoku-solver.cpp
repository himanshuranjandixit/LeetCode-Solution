class Solution {
public:
    bool iscond12(vector<vector<char>>& board, char val, int row,int col){
        for(int i=0;i<9;i++){
            if(board[row][i]==val) return false;
            if(board[i][col]==val) return false;
        }
        return true; 
    }
    bool iscond3(vector<vector<char>>& board, int row,int col,char val){
        row/=3;col/=3;
        row*=3;col*=3;
        for(int i=row;i<3+row;i++){
            for(int j=col;j<col+3;j++){
                if(board[i][j]==val) return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board,int row, int col){
        // if(row==8 && col==8) return true;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.') continue;
                for(char k='1';k<='9';k++){
                    if(iscond12(board,k,i,j) && iscond3(board,i,j,k)){
                        board[i][j]=k;
                        if(solve(board,i,j)) return true;
                        board[i][j]='.';   
                    }
                }
                return false;
            }
        }
        return true;;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board,0,0);
        
    }
};