// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
   int n , m;
    bool isValid(int i , int j){
        if(i<0 || i>=n || j<0 || j>=m) return false;
        return true;
    }
    
    bool dfs(vector<vector<char>>& board , vector<vector<int>>& vis , string word , int ind, int i , int j){
        if(!isValid(i , j) || vis[i][j]==1 || board[i][j]!=word[ind] ) return false;
        if(ind== word.length()-1) return true;
        vis[i][j]=1;
        bool a= dfs(board , vis , word , ind+1 , i+1 , j);
        bool b= dfs(board , vis , word , ind+1 , i-1 , j);
        bool c= dfs(board , vis , word , ind+1 , i , j+1);
        bool d= dfs(board , vis , word , ind+1 , i , j-1);
        vis[i][j]=0;
        return a||b|| c|| d;
    }
    
    bool isWordExist(vector<vector<char>>& board, string word) {
        // Code here
        n=board.size();
        m=board[0].size();
        vector<vector<int>> vis(n , vector<int>(m , 0));
         
        for(int i=0;i< n ;i++){
            for(int j=0; j< m ;j++){
                int ind=0;
                if(board[i][j]==word[ind] && vis[i][j]==0 ){
                    if(dfs(board , vis ,word , ind , i , j)) return true;
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
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends