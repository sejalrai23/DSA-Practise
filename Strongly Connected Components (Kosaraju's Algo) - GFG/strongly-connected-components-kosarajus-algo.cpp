// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void topoSort(int node , vector<int> adj[] , stack<int>&s, vector<int>& vis){
	    vis[node]=1;
	    for(auto it:adj[node]){
	        if(!vis[it]){
	            topoSort(it , adj, s, vis);
	        }
	    }
	    s.push(node);
	}
	
	void revDfs(int node , vector<int>& vis , vector<int> transpose[]){
	    vis[node]=1;
	    for(auto it:transpose[node]){
	        if(!vis[it]){
	            revDfs(it, vis , transpose);
	        }
	    }
	}
    int kosaraju(int V, vector<int> adj[])
    {
        //code here
        int cnt=0;
        stack<int> s;
        vector<int> vis(V, 0);
        vector<int> transpose[V];
        for(int i=0;i<V ;i++){
            if(!vis[i]){
                topoSort(i , adj , s , vis);
            }
        }
        
        for(int i=0;i<V ; i++){
            vis[i]=0;
            for(auto it :adj[i]){
                transpose[it].push_back(i);
            }
        }
        
        while(!s.empty()){
            int node=s.top();
            s.pop();
            if(!vis[node]){
                revDfs(node , vis , transpose);
                cnt++;
            }
        }
        return cnt;
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends