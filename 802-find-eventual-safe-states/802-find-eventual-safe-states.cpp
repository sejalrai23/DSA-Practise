class Solution {
public:
    bool Cycle( int node,vector<vector<int>>& adj ,vector<int>&vis, vector<int>& dfs,vector<int>& safe){
        vis[node]=1;
        dfs[node]=1;
        for(auto it : adj[node]){
            if(!vis[it]){
                if(Cycle(it,adj,vis,dfs,safe)){
                    safe[node]=true;
                    return true;
                }
             }
            else if (dfs[it]){
                    safe[node]=true;
                    return true;
           }
         
        }
        dfs[node]=0;
        return false;
        
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> vis(n,0);
        vector<int> dfs(n,0);
        vector<int> safe(n,0);
        vector<int> ans;
        for(int i=0;i<n ;i++){
            if(!vis[i]){
                Cycle(i,graph,vis,dfs,safe);
            }
            
        }
      
        for(int i=0;i<safe.size();i++){
            if(safe[i]==0){
                ans.push_back(i);
            }
        }
       
        return ans;
        
    }
};