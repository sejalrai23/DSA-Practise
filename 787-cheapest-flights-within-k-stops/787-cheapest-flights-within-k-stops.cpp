class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int , int>>> adj(n);
        for(auto it: flights){
            adj[it[0]].push_back({it[1], it[2]});
        }
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0 , src , k});
        vector<int> dist(n+1, INT_MIN);
        while(!pq.empty()){
            auto it= pq.top();
            pq.pop();
            int cost= it[0];
            int node= it[1];
            int stops=it[2];
           
            if(node==dst) return cost;
            
           if(dist[node]>stops) continue;
            dist[node]=stops;
            
            if(stops>=0){
                for(auto x: adj[node]){
                    pq.push({x.second+cost , x.first, stops-1}); 
                }
            }
        }
        return -1;
    }
};