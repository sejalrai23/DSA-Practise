class Solution {
public:
    bool isValid(int i,int j,int rows,int cols){
        if(i<0 || j<0 || i>=rows || j>=cols){
            return false;
        }
        return true;
    }
    void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2,int i,int j,int rows,int cols,bool& res){
        if(!isValid(i,j,rows,cols)){
            return ;
        }
        if(grid2[i][j]==0){
            return ;
        }
        if(grid1[i][j]!=grid2[i][j]){
            res=false;
        }
        grid2[i][j]=0;
        dfs(grid1,grid2,i+1,j,rows,cols,res);
        dfs(grid1,grid2,i,j+1,rows,cols,res);
        dfs(grid1,grid2,i-1,j,rows,cols,res);
        dfs(grid1,grid2,i,j-1,rows,cols,res);
        
        
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int cols=grid2[0].size();
        int rows=grid2.size();
        int cnt=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                bool res=true;
                if(grid2[i][j]==1){
                    dfs(grid1,grid2,i,j,rows,cols,res);
                    cnt+=res;
                    }
                }
            }
        
        return cnt;
    }
};