// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        // code here
        int n=Matrix.size();
        int m=Matrix[0].size();
        vector<vector<int>> dp(n , vector<int>(m , -1));
        for(int i=0;i< m ;i++){
            dp[n-1][i]=Matrix[n-1][i];
        }
        
        for(int i=n-2; i>=0; i--){
            for(int j=0;j< m ; j++){
                int ans=INT_MIN;
                for(int k=j-1;k<=j+1 ;k++){
                    if(k>= 0 && k<m){
                       ans=max(ans , dp[i+1][k]);
                    }
                   
                }
                dp[i][j]=ans+Matrix[i][j];
            }
        }
        return *max_element(dp[0].begin(), dp[0].end());
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}  // } Driver Code Ends