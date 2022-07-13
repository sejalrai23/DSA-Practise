// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    bool isValid(int i, int j , int n ){
        if(i<0 || i>=n || j<0 || j>=n) return false;
        return true;
    }
    bool dfs(vector<vector<int>> & grid , vector<vector<int>>& vis , int i , int j , int n ){
       
        if(!isValid(i , j , n )) return false;
        if(vis[i][j]==1 || grid[i][j]==0) return false;
        if(grid[i][j]==2) return true;
        vis[i][j]=1;
        bool a= dfs(grid , vis , i+1, j , n );
        bool b= dfs(grid , vis , i, j+1 , n );
        bool c= dfs(grid , vis , i-1, j , n );
        bool d= dfs(grid , vis , i, j-1 , n );
        return a || b || c|| d;
        
         
    }
    bool is_Possible(vector<vector<int>>& grid) 
    {
        //code here
        int n=grid.size();
        // int m=grid[0].size();
        vector<vector<int>> vis(n , vector<int>(n , 0));
        
        for(int i=0;i<n ;i++){
            for(int j=0;j<n ;j++){
                if(grid[i][j]==1){
                   if(dfs(grid, vis , i , j , n )) return true;
                }
            }
        }
        return false;
        
        
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}  // } Driver Code Ends