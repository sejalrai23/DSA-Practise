class Solution {
public:
    void dfs(int node , vector<vector<int>> &adj, vector<int> &vis, long long & nodes){
        vis[node]=1;
        nodes++;
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it, adj , vis, nodes);
            }
        }
        return ;
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        long long ans= ((long long)n *(n-1))/2;
        vector<vector<int>> adj(n);
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n , 0);
        
        for(int i=0;i<n ;i++){
           if(!vis[i]){
               long long nodes=0; 
               dfs(i, adj , vis, nodes);
               long long cnt= (nodes*(nodes-1))/2;
               ans-=cnt;
           }
            
        }
        return ans;
    }
};