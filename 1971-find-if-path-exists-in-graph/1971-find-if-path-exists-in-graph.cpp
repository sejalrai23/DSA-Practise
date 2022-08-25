class Solution {
public:
    bool dfs(vector<vector<int>> &graph, int node , vector<int>& vis, int end){
        vis[node]=1;
        if(node==end) return true;
        
        for(auto it: graph[node]){
            if(!vis[it]){
              if(dfs(graph , it , vis , end)==true) return true;
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
       vector<vector<int>> graph(n);
        
        for(auto it: edges){
            if(it[0]==start && it[1]==end || it[0]==end && it[1]==start) return true;
            
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
        vector<int> vis(n,0);
        return dfs(graph , start , vis , end);
        
       
        
    }
};

// TC: SAME AS BFS 