class Solution {
public:
    int dp[102][102];
    int empty=1;
    bool isValid(int i , int j , int m , int n){
        if(i<0 || i>=m || j<0 || j>=n) return false;
        return true;
    }
    
    
    int dfs(int m , int n , int i , int j , vector<vector<int>>& vis, vector<vector<int>>& grid , int cnt){
        if(!isValid(i , j , m , n) || vis[i][j]==3 || grid[i][j]==-1) return 0; 
        // if(dp[i][j]!=-1) return dp[i][j];
        
        if(grid[i][j]==2){
            // cout<< cnt<<"-"<<empty<<endl;
            if(cnt==empty) return 1;
        }
        
        

        
        vis[i][j]=3;
        int up= dfs(m , n , i-1 , j, vis, grid ,cnt+1);
        int left= dfs(m , n , i , j-1, vis,grid,  cnt+1);
        int down= dfs(m , n , i+1 , j, vis,grid, cnt+1);
        int right= dfs(m , n , i, j+1, vis,grid, cnt+1);
        vis[i][j]=0;
        return right+down+up+left;
    }
    

    int uniquePathsIII(vector<vector<int>>& grid) {
         memset(dp , -1 , sizeof(dp));
        int m= grid.size();
        int n= grid[0].size();
        vector<vector<int>> vis(m ,vector<int>( n , 0));
        int ans=0;
        int startx=0, starty=0;
        for(int i=0;i< m ;i++){
            for(int j=0;j< n ;j++){
                if(grid[i][j]==1){
                    startx=i;
                    starty=j;
                    
                }else if(grid[i][j]==0) empty++;
            }
        }
        // cout<<empty<<endl;
        
        return dfs(m , n , startx , starty , vis , grid , 0);
    }
};