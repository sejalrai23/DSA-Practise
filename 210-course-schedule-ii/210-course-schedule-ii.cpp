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
    
    void topo(vector<vector<int>>& adj , int node , stack<int> &st, vector<int>& vis){
        vis[node]=1;
        for(auto it: adj[node]){
            if(!vis[it]){
                topo(adj , it , st , vis);
            }
        }
        st.push(node);
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        stack<int> st;
        vector<vector<int>> adj(numCourses);
        
        for(auto it: pre){
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis1(numCourses , 0);
        vector<int> dfs(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(!vis1[i]){
                if(detectCycle(adj, vis1, dfs, i)){
                    return {};
                }
            }
        }
        vector<int> vis(numCourses,0);
        
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                topo(adj , i , st , vis);
            }
        }
        
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
        
        
    }
};