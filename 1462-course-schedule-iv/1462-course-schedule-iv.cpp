class Solution {
public:
    stack<int> s;
    void dfs(vector<vector<int>>& adj , int node , vector<int>& vis){
        vis[node]=1;
        for(auto it : adj[node]){
           
            if(!vis[it]){
                
                dfs(adj , it , vis);
            }
        }
        s.push(node);
    }
    vector<bool> checkIfPrerequisite(int num, vector<vector<int>>& pre, vector<vector<int>>& queries) {
        vector<bool> ans(queries.size(), 0);
        if(pre.size()==0) return ans;
        vector<vector<int>> adj(num);
        vector<vector<int>> connected(num , vector<int>(num, 0));
        for(auto it : pre){
            adj[it[0]].push_back(it[1]);
           
            
        }
        vector<int> vis(num , 0);
        for(int i=0;i<num;i++){
            if(!vis[i]){
                dfs(adj , i , vis);
            }
        }
       
        
        while(!s.empty()){
            int node=s.top();
            s.pop();
            queue<int> q;
            q.push(node);
            vector<int> visited(num, 0);
            while(!q.empty())
            {
                int t = q.front();
                q.pop();
                if(!visited[t])
                {
                    visited[t] = 1;
                    for(auto &e: adj[t])
                    {
                        connected[node][e] = 1;
                        q.push(e);
                    }
                }
            }
        }
       
        for(int i=0;i<queries.size();i++){
            ans[i]=connected[queries[i][0]][queries[i][1]];
            
        }
        
        return ans;
    }
};