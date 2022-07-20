class Solution {
public:
    void dfs(vector<vector<int>>& adj ,int ind, vector<int>& vis  , vector<int> & ans){
        vis[ind]=1;
        for(int i=1;i<=4;i++){
            bool f=false;
            
            for(auto it: adj[ind]){
                if(ans[it-1]==i){
                    f=true;
                    break;
                }
            }
            
            if(!f){
                ans[ind-1]=i;
            }
        }
       
        
    }
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> adj(n+1);
        
        for(auto it : paths){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int> vis(n+1 , 0);
        vector<int> ans(n, 0);
        for(int i=1;i<=n ;i++){
            if(!vis[i]){
            dfs(adj , i ,vis , ans);
                }
        }
        
        return ans;
        
    }
};