class Solution {
public:
    bool isValid(int n , int m , int i, int j){
        if(i<0 || i>=n ||j<0 || j>=m){
            return false;
        }
        return true;
    }
    void dfs(vector<vector<int>>& grid , vector<vector<int>>& vis , int &ans , int sum , int i , int j){
        if(!isValid(grid.size(), grid[0].size(), i , j) || grid[i][j]==0 || vis[i][j]==1){
            ans=max(ans,sum);
            return;
        } 
        
        // cout<<"*"<<endl;
        vis[i][j]=1;
         // cout<<sum<<endl;
       
        dfs(grid, vis , ans , sum+grid[i][j] , i+1, j); 
      
        dfs(grid, vis , ans , sum+grid[i][j] , i-1, j);
       
        dfs(grid, vis , ans , sum+grid[i][j] , i, j+1);
        
        dfs(grid, vis , ans , sum+grid[i][j] , i, j-1);
         // ans=max(ans,sum);
        vis[i][j]=0;
        
        
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size(),0));
        int ans=0;
        int st, end;
         for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]!=0) {
                    dfs(grid,vis,ans , 0 , i , j);
                }
            }
        }
        return ans;
        
        
    }
};