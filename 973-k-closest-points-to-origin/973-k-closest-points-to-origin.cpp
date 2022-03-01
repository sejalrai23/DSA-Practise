class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& p, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        for(int i=0;i<p.size();i++){
            pq.push({(p[i][0]*p[i][0] + p[i][1]*p[i][1]),i});
        }
        while(k){
            auto it=pq.top();
            ans.push_back(p[it.second]);
            pq.pop();
            k--;
            
        }
        return ans;
    }
};