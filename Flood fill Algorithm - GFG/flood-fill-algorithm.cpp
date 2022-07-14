// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
   bool isValid(int i,int j , int n , int m){
       if(i<0 || i>=n || j<0 || j>=m) return false;
       return true;
   }
   
   void dfs(vector<vector<int>>& image , int i , int j , int n , int m , int col , int newcol){
       if(!isValid(i , j , n , m) || image[i][j]==newcol || image[i][j]!=col) return;
       image[i][j]=newcol;
       dfs(image , i+1 , j , n , m , col , newcol);
       dfs(image , i , j-1 , n , m , col , newcol);
       dfs(image , i-1 , j , n , m , col , newcol);
       dfs(image , i , j+1 , n , m , col , newcol);
       return;
   }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        int col=image[sr][sc];
        int n=image.size();
        int m=image[0].size();
        dfs(image , sr , sc, n , m , col , newColor);
        return image;
        
        
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends