class Solution {
public:
    bool BipartiteBFS(vector<vector<int>>& graph , int color[], int node){
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
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        int color[n];
        memset(color,-1,sizeof(color));
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(!BipartiteBFS(graph,color,i)){
                    return false;
                }
            }
        }
        return true;
    }
};