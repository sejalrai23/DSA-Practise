class Solution {
public:
      bool BipartiteBFS(vector<vector<int>>& graph , vector<int>& color, int node){
        queue<int> q;
        q.push(node);
        color[node]=1;
        while(!q.empty()){
            int n=q.front();
            q.pop();
            for(auto it : graph[n]){
                if(color[it]==-1){
                    color[it]=1-color[n];
                    q.push(it);
                }else if(color[it]==color[n]){
                    return false;}
            }
        }
        return true;
    
    }
    
    bool possibleBipartition(int n, vector<vector<int>>& dis) {
        vector<int> vis(n+1,-1);
        vector<vector<int>> gr(n+1);
        for(auto d:dis){
            gr[d[0]].push_back(d[1]);
            gr[d[1]].push_back(d[0]);
        }
        
        // for(int i=1;i<=n;i++){
        //     if(!vis[i]){
        //         if(checkCycle(i,-1,vis,gr)){
        //             return false;
        //         }
        //     }
        // }
        
          for(int i=1;i<=n;i++){
            if(vis[i]==-1){
                if(!BipartiteBFS(gr,vis,i)){
                    return false;
                }
            }
        }
        return true;
        
    }
};