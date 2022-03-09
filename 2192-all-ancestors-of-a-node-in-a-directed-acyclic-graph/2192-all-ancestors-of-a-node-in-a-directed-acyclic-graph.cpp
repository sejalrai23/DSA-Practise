class Solution {
public:
    
    void dfs(vector<int> adj[], vector<bool> &vis,int node,int j,vector<vector<int>>& ans){
         vis[j]=true;
        for(auto &it: adj[j]){
            if(!vis[it]){
                 ans[it].push_back(node);
                dfs(adj,vis,node,it,ans);
            }
        }
    
        
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int> adj[n+1];
        vector<vector<int>> ans(n);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
        }
        vector<int> res;
        for(int i=0;i<n;i++){
           vector<bool> vis(n);
            dfs(adj , vis ,i,i,ans);
        
        }
        return ans;
    }
};