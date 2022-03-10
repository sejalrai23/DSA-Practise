
class Solution {
public:
    bool isValid(int i,int j , int row,int col){
        if( i<0 || j<0 || i>=row ||j>=col){
            return false;
        }
        return true;
    }
    void dfs( vector<vector<char>>& grid, int i,int j, int rows,int cols){
        if(!isValid(i,j,rows,cols)){
            return;
        }
        if(grid[i][j]=='0'){
            return;
        }
        grid[i][j]='0';
        dfs(grid,i+1,j,rows,cols);
        dfs(grid,i-1,j,rows,cols);
        dfs(grid,i,j-1,rows,cols);
        dfs(grid,i,j+1,rows,cols);
    }
   int numIslands(vector<vector<char>>& grid) {
        int cnt=0;
        int rows=grid.size();
        int cols=grid[0].size();
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]=='1'){
                    dfs(grid,i,j,rows,cols);
                    cnt++;
                }
                
                
            }
        }
        return cnt;
        
    }
};