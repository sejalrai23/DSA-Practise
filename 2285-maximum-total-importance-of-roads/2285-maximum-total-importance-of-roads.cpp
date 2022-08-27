class Solution {
public:
   
    
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<vector<int>> adj(n);
        for(auto x :roads){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        vector<pair<int,int>> cons;
        for(int i=0;i<n;i++){
            // cout<<adj[i].size()<<endl;
            cons.push_back(make_pair(i,adj[i].size()));
        }
    
        sort(cons.begin(), cons.end(), [](auto &left, auto &right) {
             return left.second > right.second;
       });
        vector<int> assign(n,0);
        int k=n;
        for(auto x : cons){
            assign[x.first]=k;
            k--;
        }

        long long ans=0;
        for(auto x: roads){
            ans+=(assign[x[0]]+assign[x[1]]);
        }
        return ans;
    } 
};