class Solution {
public:
    
    void dfs(int node,int& cnt , vector<int>& vis,vector<int> adj[]){
        vis[node]=1;
        for(auto& it : adj[node]){
            if(!vis[abs(it)]){
                if(it>0){
                    cnt++;}
                dfs(abs(it),cnt,vis,adj);    
                
               
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
         int cnt=0;
        dfs(0,cnt,vis, adj);
        
        return cnt;
    }
};