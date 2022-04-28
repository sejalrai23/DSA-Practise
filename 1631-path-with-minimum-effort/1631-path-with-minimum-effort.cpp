class Solution {
public:
    vector<int> x_dir={1,0,-1,0};
    vector<int> y_dir = {0,1,0,-1};
    vector<vector<bool>> vis;
    bool isValid(int n, int m , int x , int y){
        if(x<0 ||y<0 ||x>n-1 ||y>m-1){
            return false;
        }
        return true;
    }
    bool dfs(int n, int m , vector<vector<int>>&heights , int k , int x , int y){
        vis[x][y]=true;
        if(x==n-1 && y==m-1){
            return true;
        }
        for(int i=0;i<4;i++){
            int x_curr=x+x_dir[i];
            int y_curr=y+y_dir[i];
            if(isValid(n,m,x_curr, y_curr) && !vis[x_curr][y_curr] && abs(heights[x_curr][y_curr]-heights[x][y])<=k){
                if(dfs(n, m, heights, k , x_curr , y_curr)){
                    return true;
                }
            }
        }
        return false;
    }
    bool isPossible(vector<vector<int>>& heights , int mid, int n, int m){
        vis.assign(n,vector<bool>(m,false));
        return dfs(n, m, heights,mid,0,0);
        
        
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        
        int st=0, end=1e6;
        while(st<=end){
            int mid=st+ (end-st)/2;
            if(isPossible(heights,mid, n, m)){
                end=mid-1;
            }else{
                st=mid+1;
            }
        }
        return st;
        
        
    }
};