class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        vector<int> adj[n+1];
        
        for(int i=0;i<edges.size();i++){
            if(edges[i][0]==start && edges[i][1]==end){
                return true;
            }
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> vis(n+1,0);
        queue<int> q;
        q.push(start);
        vis[start] = 1; 
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            if(curr == end)
                return 1; 
            for(auto it : adj[curr]){
                if(!vis[it]){
                    vis[it] = 1; 
                    q.push(it);
                }
            }
        }
        
        return false;
        
       
        
    }
};

// TC: SAME AS BFS 