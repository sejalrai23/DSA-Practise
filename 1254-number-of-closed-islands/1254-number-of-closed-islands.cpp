class Solution {
public:
   bool isValid(int i,int j,int rows, int cols){
       if(i<0|| j<0 || i>=rows || j>=cols){
           return false;
       }
       return true;
   } 
    bool dfs(vector<vector<int>> & grid, int i, int j, int rows, int cols){
        if(!isValid(i,j,rows,cols)){
            return false;
        }
        if(grid[i][j]==1){
            return true;
        }
        grid[i][j]=1;
        bool a1= dfs(grid,i+1,j,rows,cols);
        bool a2= dfs(grid,i,j+1,rows,cols);
        bool a3= dfs(grid,i-1 , j,rows,cols);
        bool a4= dfs(grid,i,j-1,rows,cols);
        return a1&&a2&&a3&&a4;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int cols=grid[0].size();
        int rows= grid.size();
        int res=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==0){
                    res+=dfs(grid,i,j,rows,cols);
                }
            }
        }
        return res;
    }
};