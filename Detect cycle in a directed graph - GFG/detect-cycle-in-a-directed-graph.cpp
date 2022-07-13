// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(vector<int> adj[],vector<int>& vis, vector<int>& selfDfs , int node){
        vis[node]=1;
        selfDfs[node]=1;
        for(auto it : adj[node]){
            if(!vis[it]){
                if(dfs(adj , vis , selfDfs , it)) return true;
            }else if(selfDfs[it]){
                return true;
            }
        }
        selfDfs[node]=0;
        return false;
        
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> vis(V, 0);
        vector<int> selfDfs(V, 0);
        for(int i=0;i<V ;i++){
            if(!vis[i]){
                if(dfs(adj , vis , selfDfs, i)) return true;
            }
        }
        return false;
        
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends