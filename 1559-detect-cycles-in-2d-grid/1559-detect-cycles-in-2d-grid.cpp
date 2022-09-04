class Solution {
public:
    bool isValid(int x , int y , int n , int m){
        if(x<0 || x>=n || y<0 || y>=m) return false;
        return true;
    }
    
    bool dfs(vector<vector<char>>& grid, int x , int y , int st , int end , int n , int m , char letter, vector<vector<int>>& vis){
        
        // cout<<x<<"-"<<y<<"-"<<st<<"-"<<end<<"-"<<letter<<endl;
        
        if(!isValid(x, y , n , m) || grid[x][y]!= letter) return false;
        
        if(vis[x][y] ) return true;
        
        vis[x][y]=1;
  
        char p= grid[x][y];
    
    
        if((x+1!=st || y!=end ) && dfs(grid ,x+1 ,y , x , y , n , m , p,vis))  return true;
        if((x-1!=st || y!=end) &&  dfs(grid ,x-1 ,y , x , y , n , m , p, vis))  return true;
        if((x!=st || y+1!=end) && dfs(grid ,x,y+1 , x , y , n , m , p, vis))    return true;
        if((x!=st ||  y-1!=end) && dfs(grid ,x ,y-1 , x , y , n , m , p, vis))  return true;
    
        
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int n= grid.size();
         int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int i=0;i<n ;i++){
            for(int j=0;j<m ;j++){
                if(!vis[i][j] && dfs(grid ,i , j , -1 , -1 , n , m , grid[i][j] , vis)){
                    cout<<i<<'-'<<j<<endl;
                    return true;
                }
            }
        }
        return false;
    }
};