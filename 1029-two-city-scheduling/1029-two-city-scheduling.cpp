class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        priority_queue<pair<int,int>> pq;
        vector<int> v;
        for(int i=0;i<costs.size();i++){
           pq.push(make_pair(abs(costs[i][0]-costs[i][1]),i));
        }
        int a=0, b=0, sum=0;
        // cout<<pq.size()<<endl;
       while(!pq.empty()){
           if(b<costs.size()/2 && a<costs.size()/2){
               sum+=min(costs[pq.top().second][0], costs[pq.top().second][1]);
               if(costs[pq.top().second][0]>= costs[pq.top().second][1]){
                   b++;
               }else{
                   a++;
               }
           }else{
               if(a!=costs.size()/2){
                   sum+=costs[pq.top().second][0];
               }else{
                    sum+=costs[pq.top().second][1];
               }
           }
           cout<<pq.top().first<<" "<<pq.top().second<<endl;
           pq.pop();
            
            
        }
        return sum;
        
    }
};