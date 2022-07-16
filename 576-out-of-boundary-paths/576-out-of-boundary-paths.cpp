class Solution {
public:
    int mod= 1e9+7;
    int recur(int row, int col , int m , int n , int move ,  vector<vector<vector<int>>>& dp){
        if(row<0 || row>=m || col<0 || col>=n) return 1;
        if(move==0) return 0;
        if( dp[row][col][move]!=-1) return  dp[row][col][move];
        int moves=0;
        moves= (moves +recur(row +1 , col , m , n, move-1 , dp))%mod;
        moves=(moves+ recur(row -1 , col , m , n, move-1 , dp))%mod;
        moves=( moves+recur(row  , col-1 , m , n, move-1 , dp))%mod;
        moves=(moves+ recur(row  , col+1 , m , n, move-1 , dp))%mod;
        return dp[row][col][move]=moves;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(m +1, vector<vector<int>>(n+1 , vector<int>(maxMove+1 , -1)));
        return recur(startRow , startColumn ,  m ,  n ,  maxMove , dp);
    }
};