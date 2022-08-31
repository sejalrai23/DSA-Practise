class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>> adj(n);
        for(auto it:roads){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=i+1 ; j<n ;j++){
               int cnt1=0;
               for(auto x: adj[j]){
                   if(x==i){
                      cnt1=1;
                       break;
                   }
               }
                int m=adj[i].size();
                int n=adj[j].size();
               maxi=max( m+n-cnt1,maxi);    
            }      
        }
        return maxi;
        
    }
};