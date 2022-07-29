class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int , long long>>> adj(n);
        
        for(auto it: roads){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        
        priority_queue<pair<long long, long long> , vector<pair<long long , long long>> , greater<pair<long long, long long>>> pq;
        
        vector<long long > dist(n , LLONG_MAX);
        vector<long long> ways(n , 0);
        int mod=1e9+7;
        
        pq.push({0, 0});
        dist[0]=0;
        ways[0]=1;
        
        
        while(!pq.empty()){
           long long totalDist = pq.top().first;
            long long currentNode = pq.top().second;
            pq.pop();
            for(auto neigh: adj[currentNode]){
                int neighbor = neigh.first;
                long long newDist = neigh.second + totalDist;
                

                if (newDist < dist[neighbor]) {
                    dist[neighbor] = newDist;
                    ways[neighbor] = ways[currentNode];
                    pq.push({ dist[neighbor], neighbor });
                }
                
                else if (newDist == dist[neighbor]) {
                    ways[neighbor] = (ways[neighbor] + ways[currentNode]) % mod;
                }
            }
            
        }
        return ways[n-1];
    }
};