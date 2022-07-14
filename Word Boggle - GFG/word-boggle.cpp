// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
public:
  int n , m;
   bool isValid(int i , int j ){
       if(i<0 || i>=n || j<0 || j>=m) return false;
       return true;
   }
   
   bool dfs(vector<vector<char>> & board , vector<vector<int>> & vis , string &s , int ind , int i , int j){
       if(!isValid(i , j) || vis[i][j]==1 || board[i][j]!=s[ind]) return false;
       if(ind==s.length()-1) return true;
       vis[i][j]=1;
    //   ind++;
       bool a= dfs(board , vis , s, ind+1 , i+1, j);
       bool b= dfs(board , vis , s, ind+1 , i+1, j+1);
       bool c= dfs(board , vis , s, ind+1 , i+1, j-1);
       bool d= dfs(board , vis , s, ind+1 , i, j-1);
       bool e= dfs(board , vis , s, ind+1 , i-1, j-1);
       bool f= dfs(board , vis , s, ind+1 , i-1, j+1);
       bool g=dfs(board , vis , s, ind +1, i-1, j);
       bool h= dfs(board , vis , s, ind+1 , i, j+1);
      vis[i][j]=0;
       return a|| b|| c|| d|| e|| f|| g|| h;
       
   }
	vector<string> wordBoggle(vector<vector<char> >& board, vector<string>& dictionary) {
	    // Code here
	    n=board.size();
	    m=board[0].size();
	    vector<vector<int>> vis(n , vector<int>(m , 0));
	    set<string> ans;
	    for(auto it : dictionary){
	        int ind=0;
	        for(int i=0;i<n;i++){
	            for(int j=0;j<m ;j++){
	                if(board[i][j]==it[ind] && vis[i][j]==0){
	                   // ind++;
	                    if(dfs(board , vis , it , ind , i , j)){
	                   // cout<<"*"<<endl;
	                    ans.insert(it);
	                }
	                }
	                
	            }
	        }
	    }
	    vector<string> res;
	    for(auto it: ans){
	        res.push_back(it);
	    }
	   // sort(ans.begin(),ans.end());
	    return res;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> dictionary;
        for (int i = 0; i < N; ++i) {
            string s;
            cin >> s;
            dictionary.push_back(s);
        }
        
        int R, C;
        cin >> R >> C;
        vector<vector<char> > board(R);
        for (int i = 0; i < R; i++) {
            board[i].resize(C);
            for (int j = 0; j < C; j++) cin >> board[i][j];
        }
        Solution obj;
        vector<string> output = obj.wordBoggle(board, dictionary);
        if (output.size() == 0)
            cout << "-1";
        else {
            sort(output.begin(), output.end());
            for (int i = 0; i < output.size(); i++) cout << output[i] << " ";
        }
        cout << endl;
    }
}
  // } Driver Code Ends