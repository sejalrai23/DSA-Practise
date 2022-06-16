// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int recur(int ind , int prev , int arr[], int N , vector<vector<int>>& dp){
        if(ind==N) return 0;
        
        if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
        int notTake= recur(ind+1 , prev , arr , N, dp);
        int take=0;
        if(prev==-1 || arr[ind]== arr[prev]+1 || arr[ind]==arr[prev]-1){
            take=1+ recur(ind+1 , ind, arr , N, dp);
        }
        dp[ind][prev+1]= max(take,notTake);
    }
    int longestSubsequence(int N, int A[])
    {
        // code here
        vector<vector<int>> dp(N , vector<int>(N+1 , -1));
        return recur(0 , -1, A , N , dp);
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int A[N];
        for(int i = 0;i < N;i++)
            cin>>A[i];
        
        Solution ob;
        cout<<ob.longestSubsequence(N, A)<<endl;
    }
    return 0;
}  // } Driver Code Ends