// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the number of 'X' total shapes.
    int n , m;
    bool isvalid(int i, int j){
        if(i<0 || i>=n || j<0 || j>=m ) return false;
        return true;
    }
    void dfs(vector<vector<char>> & grid , int i , int j ){
        if(!isvalid(i , j) || grid[i][j]=='O') return ;
        grid[i][j]='O';
        dfs(grid , i +1 , j);
        dfs(grid , i-1 , j);
        dfs(grid , i, j+1);
        dfs(grid , i, j-1);
    }
    
    int xShape(vector<vector<char>>& grid) 
    {
        // Code here
        n=grid.size();
        m=grid[0].size();
        int ans=0;
        for(int i=0;i<n ;i++){
            for(int j=0;j< m ;j++){
                if(grid[i][j]=='X'){
                    dfs(grid , i , j);
                    ans++;
                }
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.xShape(grid);
		cout << ans <<'\n';
	}
	return 0;
}  // } Driver Code Ends