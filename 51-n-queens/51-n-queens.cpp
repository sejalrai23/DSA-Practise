class Solution {
public:
    void solve(vector<vector<string>>&ans, vector<string> & board, int n, int col, vector<int> &leftRow, vector<int>& upperD , vector<int>& lowerD){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(leftRow[row]==0 && upperD[n-1 + col- row]==0 && lowerD[row+col]==0){
                board[row][col]='Q';
                leftRow[row]=1;
                upperD[n-1+col-row]=1;
                lowerD[row+col]=1;
                solve(ans,board,n,col+1,leftRow,upperD, lowerD);
                board[row][col]='.';
                leftRow[row]=0;
                upperD[n-1+col-row]=0;
                lowerD[row+col]=0;
            }
        }
        
    }
    
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        vector<int> leftRow(n,0), upperD(2*n-1,0) , lowerD(2*n-1,0);
        solve(ans , board, n, 0 , leftRow, upperD, lowerD);
        return ans;
        
    }
};