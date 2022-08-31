class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succ, int start, int end) {   
        vector<vector<pair<int , double>>> vec(n);
        
        for(int i=0;i<edges.size() ;i++){
            vec[edges[i][0]].push_back({edges[i][1], succ[i]});
            vec[edges[i][1]].push_back({edges[i][0], succ[i]});
        }
        priority_queue<pair<double,int>> pq;
        vector<double> dist(n, 0.0);
        dist[start]=1.0;
        pq.push({1.0,start});
        while(!pq.empty()){
            double d= pq.top().first;
            int prev= pq.top().second;
            pq.pop();
            // cout<<d<<"-"<<prev<<endl;
            for(auto it: vec[prev]){
                int next=it.first;
                double nextDist=it.second;
                if(dist[next]< dist[prev]*nextDist){
                    dist[next]= dist[prev]*nextDist;
                    pq.push({dist[next], next});
                }
            }
        }
        return dist[end];
        
    }
};