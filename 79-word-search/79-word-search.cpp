class Solution {
public:
    bool isValid(int n, int m , int i, int j){
        if(i<0 || i>=n || j<0 || j>=m){
            return false;
        }
        return true;
    }
    
    bool dfs(vector<vector<char>>& board , string word , int i , int j , int ind, vector<vector<int>>& vis){
        if(!isValid(board.size(), board[0].size() , i , j) || board[i][j]!= word[ind] || vis[i][j]==1){
            return false;
        }
        
        if(ind==word.length()-1){
            return true;
        }
        vis[i][j]=1;
        // ind++;
        // cout<<ind<<endl;
        int p1=dfs(board, word , i +1 , j, ind+1 , vis);
        int p2= dfs(board ,word , i-1 , j , ind+1 , vis);
        int p3=dfs(board , word , i , j+1 , ind+1, vis);
        int p4= dfs(board, word , i , j-1 , ind+1 , vis);
        vis[i][j]=0;
        return  p1||p2 || p3 ||p4;
    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<int>> vis(board.size(), vector<int> (board[0].size(),0));
        int ind=0;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[ind]){
                    if(dfs(board , word , i , j , ind, vis)){
                        return true;
                    }
                }
                
            }
        }
        return false;
        
    }
};