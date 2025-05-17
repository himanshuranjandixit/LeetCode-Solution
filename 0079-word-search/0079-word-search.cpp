class Solution {
public:
    bool backtrack(int i,int j,int k, string& word,vector<vector<char>>& board){
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j]!=word[k]){
            return false;
        }
        if(k==word.size()-1) return true;
        char temp=board[i][j];
        board[i][j]='&';
        if(backtrack(i,j+1,k+1,word,board) || backtrack(i-1,j,k+1,word,board) || backtrack(i,j-1,k+1,word,board) || backtrack(i+1,j,k+1,word,board)){
            return true;
        }
        board[i][j]=temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(backtrack(i,j,0,word,board)) return true;
            }
        }
        return false;
        
    }
};