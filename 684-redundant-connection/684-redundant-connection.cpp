class Solution {
public:
    unordered_set<int> cycle;
    int cycleStart=-1;
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<vector<int>> graph(n+1);
        vector<bool> vis(n+1);
        for(auto e : edges){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        dfs(graph , vis , 1 , -1);
        for(int i=n-1;i>=0;i--){
            if(cycle.count(edges[i][0]) && cycle.count(edges[i][1])){
                return edges[i];
            }
        }
        return {};
        
    }
    
    void dfs(vector<vector<int>> & graph , vector<bool>& vis , int node , int par){
        if(vis[node]){
            cycleStart=node;
            return;
        }
        vis[node]=true;
        for(auto it: graph[node]){
            if(it==par) continue;
            if(cycle.empty()) dfs(graph,vis,it,node);
            if(cycleStart!=-1) cycle.insert(node);
            if(node==cycleStart) {
                cycleStart=-1;
                return ;
            }
        }
    }
};