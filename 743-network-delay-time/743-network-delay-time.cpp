class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto x:times){
            adj[x[0]].push_back(make_pair(x[1],x[2]));
        }
        vector<int> vis(n+1,INT_MAX);
        queue<int> q;
        q.push(k);
        vis[k]=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto x: adj[node]){
                // cout<<x.first<<"-"<<x.second<<endl;
                if(vis[x.first]> vis[node]+x.second){
                    vis[x.first]=vis[node]+x.second;
                    q.push(x.first);     
                }       
            }
        }
        int res=0;
        for(int i=1;i<vis.size();i++){
            if(vis[i]==INT_MAX){
                return -1;
            }
            res=max(res,vis[i]);
        }
        return res;
    }
};