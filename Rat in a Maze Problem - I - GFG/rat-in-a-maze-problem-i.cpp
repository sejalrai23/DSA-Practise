// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string> ans;
    bool isValid(int i, int j , int n){
        if(i<0 || i>=n || j<0 || j>=n){
            return false;
        }
        return true;
    }
    
    void dfs(vector<vector<int>>&m , int i , int j , int n, string res, vector<vector<int>>& vis){
        if(!isValid(i, j ,n) || m[i][j]==0|| vis[i][j]==1){
            return ;
        }
        vis[i][j]=1;
        if(i==n-1 && j==n-1){
            ans.push_back(res);
        }
        dfs(m , i+1, j , n ,res+'D',vis);
        dfs(m , i-1 , j , n ,res+'U',vis);
        dfs(m , i , j+1, n, res+'R',vis);
        dfs(m , i , j-1, n , res+'L',vis);
        
        vis[i][j]=0;
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<vector<int>> vis(n, vector<int>(n,0));
        string res;
        dfs(m , 0, 0, n, res,vis);
        return ans;
       
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends