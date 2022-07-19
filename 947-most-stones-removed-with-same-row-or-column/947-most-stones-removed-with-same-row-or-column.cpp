class Solution {
public:
    int ans=0;
    void dfs(vector<vector<int>>& stones , int ind , vector<int>& vis){
        vis[ind]=1;
        for(int i=0;i< stones.size();i++){
            if(!vis[i] && (stones[i][0]==stones[ind][0] || stones[i][1]==stones[ind][1])){
                dfs(stones , i , vis);
                ans++;
            }
        }
    }

    int removeStones(vector<vector<int>>& stones) {
          int n=stones.size();
          vector<int> vis(n , 0);
        
          for(int i=0;i<n ;i++){
              if(!vis[i]){
                  dfs(stones, i , vis );
              }
          }
        return ans;
         
    }
};