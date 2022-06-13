// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int recursion(int N , int arr[], vector<vector<int>> &dp , int target ){
        if(N==0 && target==0) return 1;
        
        if(N==0) return 0;
        
        if(target==0) return 1;
        
        if(arr[N-1]<=target){
           return  dp[N][target]=recursion(N-1 , arr , dp , target-arr[N-1] ) || recursion(N -1, arr , dp , target);
            
        }
            
        return dp[N][target]=recursion(N-1 , arr , dp , target);
        
        
    }
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum=0;
        for(int i=0;i<N;i++){
            sum+=arr[i];
        }
        if(sum%2!=0) return 0;
        int target=sum/2;
        vector<vector<int>> dp(N+1, vector<int>(target+1, -1));
        return recursion(N , arr , dp , target);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends