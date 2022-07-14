// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
      bool detectCycle(vector<vector<int>> & adj , vector<int>& vis , vector<int>& dfs , int node){
        vis[node]=1;
        dfs[node]=1;
        for(auto it: adj[node]){
            if(!vis[it]){
                if(detectCycle(adj , vis, dfs, it)){
                    return true;
                }
            }else if(dfs[it]){
                return true;
            }
        }
        dfs[node]=0;
        return false;
        
        
            
    }
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    vector<vector<int>> adj(N);
	    vector<int> vis(N ,0);
	     vector<int> dfs(N ,0);
	    for(auto it:prerequisites){
	        adj[it.second].push_back(it.first);
	    }
	    for(int i=0;i<N;i++){
	        if(!vis[i]){
	            if(detectCycle(adj , vis , dfs, i)) return false;
	        }
	    }
	    return true;
	    
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}  // } Driver Code Ends