class Solution {
public:
    bool isValid(int i,int j , int row, int col){
        if(i<0||j<0 ||i>=row||j>=col){
            return false;
        }
        return true;
    }
    void dfs(vector<vector<char>>& board , int i,int j , int row,int col){
        if(!isValid(i,j,row,col)){
            return;
        }
        if(board[i][j]=='X'){
            return;
        }
        if(board[i][j]=='O') {
            board[i][j]='#';
            dfs(board, i+1, j,row,col); //down
            dfs(board, i-1, j,row,col); //up
            dfs(board, i, j+1,row,col); //right
            dfs(board, i, j-1,row,col); //left
        }
        
    }
    void solve(vector<vector<char>>& board) {
        int row=board.size();
        int col=board[0].size();
        for(int i=0;i<row;i++){
            if(board[i][0]=='O'){
                dfs(board,i,0,row,col);
            }
            if(board[i][col-1]=='O'){
                dfs(board,i,col-1,row,col);
            }
           
        }
        for(int j=0;j<col;j++){
            if(board[0][j]=='O'){
                dfs(board,0,j,row,col);
            }
            if(board[row-1][j]=='O'){
                dfs(board,row-1,j,row,col);
            }
           
        }
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }
                if(board[i][j]=='#'){
                    board[i][j]='O';
                }
            }
        }
        
    }
};