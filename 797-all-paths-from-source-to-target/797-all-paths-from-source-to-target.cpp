class Solution {
private:
     vector<vector<int>> ans;
public:
   
    void DFS(int node, vector<int>& vis, vector<vector<int>>& graph ,int target){
        // vis[node]=1;
        vis.push_back(node);
        if(node==target-1){
            ans.push_back(vis);
            // return;
        }
        for(auto it: graph[node]){
                
           DFS(it, vis, graph,target);
           vis.pop_back();   
        }
      
        
    }
    
    
    
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int size=graph.size();
        // vector<vector<int>> ans;
        vector<int> vis;
        DFS(0,vis, graph, size);
        return ans;
        
    }
};