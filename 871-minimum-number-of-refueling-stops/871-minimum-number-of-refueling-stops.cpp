class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n=stations.size();
        priority_queue<int> pq;
        int s=startFuel;
        int ans=0;
        int i=0;
        while(s<target){
            while(i<n && s>=stations[i][0]){
                pq.push(stations[i][1]);
                i++;
            }
            if(pq.empty()) return -1;
            int dis=pq.top();
            pq.pop();
            s+=dis;
            ans++;
        }
        return ans;
    }
};