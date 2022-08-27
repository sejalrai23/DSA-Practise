class Solution {
public:
    int cnt =0;
    void dfs(int node, vector<int>& vis,vector<int> adj[]){
        vis[node]=1;
        for(auto& it : adj[node]){
            if(!vis[abs(it)]){
                if(it>0){cnt++;};
                dfs(abs(it),vis,adj);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& con) {
        vector<int> vis(n,0);
        vector<int> adj[n];
        for (int i=0;i<con.size();i++){
            adj[con[i][0]].push_back(con[i][1]);
            adj[con[i][1]].push_back(-con[i][0]);
        }
               
        dfs(0,vis, adj);
       
        
        return cnt;
    }
};