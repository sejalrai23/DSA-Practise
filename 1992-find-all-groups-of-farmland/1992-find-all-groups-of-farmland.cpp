class Solution {
public:
    bool isValid(int i,int j,int rows,int cols){
        if(i<0|| j<0 ||i>=rows||j>=cols){
            return false;
        }
        return true;
    }
    void dfs(vector<vector<int>>& land , int i,int j ,int&x ,int&y, int rows,int cols){
        if(!isValid(i,j,rows,cols)){
            return;
        }
        if(land[i][j]==0){
            return;
        }
        x=max(i,x);
        y=max(j,y);
        land[i][j]=0;
        dfs(land,i+1,j,x,y,rows,cols);
        dfs(land,i,j+1,x,y,rows,cols);
        dfs(land,i-1,j,x,y,rows,cols);
        dfs(land,i,j-1,x,y,rows,cols);
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int rows=land.size();
        int cols=land[0].size();
        vector<vector<int>> ans;
        for(int i=0;i<rows;i++){
         
            for(int j=0;j<cols;j++){
                vector<int> res;
                int x=i, y=j;
                if(land[i][j]==1){
                  dfs(land,i,j,x,y,rows,cols);
                  ans.push_back({i,j,x,y});
                }
            }
          
        }
        return ans;
    }
};