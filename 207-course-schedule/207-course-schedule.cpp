class Solution {
public:
    bool detectCycle(vector<vector<int>> & adj , vector<int>& vis , vector<int>& dfs , int node){
        vis[node]=1;
        dfs[node]=1;
        for(auto it: adj[node]){
            if(!vis[it]){
                if(detectCycle(adj , vis, dfs, it)){
                    return true;
                }
            }else if(dfs[it]){
                return true;
            }
        }
        dfs[node]=0;
        return false;
        
        
            
    }
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        // if(pre.size()==0) return true;
        vector<vector<int>> adj(numCourses);
        for(auto it :pre){
            adj[it[1]].push_back(it[0]);
        }
        vector<int> dfs(numCourses,0);
        vector<int> vis(numCourses,0);
        
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(detectCycle(adj, vis, dfs, i)){
                    return false;
                }
            }
        }
        return true;
        
    }
};