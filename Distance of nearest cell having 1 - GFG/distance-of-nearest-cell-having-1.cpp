// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
    int n , m;
    bool isValid(int i , int j){
        if(i<0 || i>=n || j<0 || j >=m) return false;
        return true;
    }
  
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    n=grid.size();
	    m=grid[0].size();
	    vector<vector<int>> vis(n , vector<int>(m , 0));
	    queue<pair<int , int>> pq;
	    for(int i=0;i<n ;i++){
	        for(int j=0;j<m ;j++){
	            if(grid[i][j]==1){
	                pq.push({i, j});
	                grid[i][j]=0;
	                vis[i][j]=1;
	            }
	        }
	    }
	    vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
	    while(!pq.empty()){
	        int s=pq.size();
	        for(int m=0;m<s;m++){
	            int i=pq.front().first;
	            int j=pq.front().second;
	            
	            pq.pop();
	            for(auto it : dir){
	                int x=it[0]+i;
	                int y=it[1]+j;
	                if(isValid(x,y) && !vis[x][y]){
	                   
	                        grid[x][y]=grid[i][j]+1;
	                        pq.push({x, y});
	                        vis[x][y]=1;
	                    
	                }
	            }
	        }
	    }
	    return grid;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends