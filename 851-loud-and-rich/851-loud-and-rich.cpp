class Solution {
public:
    
    int dfs(int node , vector<vector<int>>& adj, vector<int>& quiet,vector<int>& ans){
        if(ans[node]>=0){
            return ans[node];
        }
        ans[node]=node;
        for(auto it: adj[node]){
           if(quiet[dfs(it,adj,quiet,ans)]<quiet[ans[node]]){
                ans[node]=ans[it];
            }
          
            
        }
        return ans[node];
        
    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n=quiet.size();
        vector<int> ans(n,-1);
         vector<vector<int>> adj(n);

        for(auto& rich : richer) {
            adj[rich[1]].push_back(rich[0]);
        }
        
        for(int i=0; i<quiet.size();i++){
              
            dfs(i, adj,quiet,ans); 
            
            
        }
        return ans;
    }
};