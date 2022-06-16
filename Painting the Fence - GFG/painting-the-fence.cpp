// { Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
  long long mod = 1e9+7;
    long long find(int post,int n,int k,vector<vector<int>> &dp,int prevColor,int prev)
    {
        if(post > n)
        return 1;
        
        if(dp[post][prev] != -1)
        return dp[post][prev];
        
        long long ans = 0 ;
        for(int c = 0;c < k;c++)
        {
            if(prev==2 && prevColor == c)
            continue;
            
            if(prevColor==c)
                ans += find(post + 1, n , k , dp , c , prev + 1);
            else
                ans += find(post + 1 , n , k , dp , c , 1);
                
            ans = ans%mod;
        }
        return dp[post][prev] = ans;
    }
    
    long long countWays(int n, int k){
        // code here
        vector<vector<int>> dp(n+1,vector<int>(3,-1));
        return find(1,n,k,dp,-1,0);
    }
};

// { Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}  // } Driver Code Ends