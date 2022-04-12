class Solution {
public:
    bool isValid(int i , int j , int m , int n){
        if(i<0 || i > n-1 || j <0 || j >m-1){
            return false;
        }
        return true;
    }
    void getCount(int i , int j , int m , int n , int& cnt0 , int &cnt1, vector<vector<int>>& board){
        if(isValid(i+1 , j , m , n)){
            board[i+1][j] ==0 ? cnt0++ : cnt1++;
        }
        if(isValid(i , j+1 , m , n)){
            board[i][j+1] ==0 ? cnt0++ : cnt1++;
        }
        if(isValid(i-1, j , m , n)){
            board[i-1][j] ==0 ? cnt0++ : cnt1++;
        }
        if(isValid(i , j-1 , m , n)){
            board[i][j-1] ==0 ? cnt0++ : cnt1++;
        }
        if(isValid(i-1 , j -1, m , n)){
            board[i-1][j-1] ==0 ? cnt0++ : cnt1++;
        }
        if(isValid(i-1 , j+1 , m , n)){
            board[i-1][j+1] ==0 ? cnt0++ : cnt1++;
        }
        if(isValid(i+1 , j+1 , m , n)){
            board[i+1][j+1] ==0 ? cnt0++ : cnt1++;
        }
        if(isValid(i+1 , j-1 , m , n)){
            board[i+1][j-1] ==0 ? cnt0++ : cnt1++;
        }
        
    }
    void gameOfLife(vector<vector<int>>& board) {
        int m=board[0].size();
        int n= board.size();
        vector<vector<int>> grid=board;
        for(int i=0;i<n;i++){
            for(int j=0;j<m ; j ++){
                // cout<<"*"<<endl;
                int cnt0=0 , cnt1=0;
                getCount(i, j, m , n , cnt0, cnt1, grid);
                // cout<<cnt0 <<"-"<< cnt1<<endl;
                if(board[i][j]==0){
                    if(cnt1==3){
                        board[i][j]=1;
                    }
                }else{
                    if(cnt1<2){
                        board[i][j]=0;
                    }else if(cnt1>3){
                        board[i][j]=0;
                    }
                }
                
            }
        }
        
    }
};