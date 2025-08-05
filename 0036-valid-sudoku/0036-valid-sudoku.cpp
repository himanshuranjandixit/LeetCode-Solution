class Solution {
public:
    bool iscond12(vector<vector<char>>& board, char val, int row,int col){
        for(int i=0;i<9;i++){
            if(board[row][i]==val ) return false;
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
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.') continue;
                char val = board[i][j];
                board[i][j] ='.'; 
                if(!iscond12(board,val,i,j)) return false;
                if(!iscond3(board,i,j,val)) return false;
                board[i][j] =val;
            }
        }
        return true;
        
    }
};