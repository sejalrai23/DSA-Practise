// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution
{
    public:
    int recur(vector<vector<int>>& dp , int ind , int target, vector<int>& coins){
        if(ind==0){
            if(target%coins[ind]==0) return target/coins[ind];
            return INT_MIN;
        }
        if(dp[ind][target]!=-1) return dp[ind][target];
        
       int notTake= recur(dp, ind-1 , target , coins);
       int take=INT_MIN;
       if(coins[ind]<=target){
           take= 1+recur(dp, ind , target-coins[ind], coins);
       }
        return dp[ind][target]= max(take , notTake);
        
    }
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        int m= 3;
        vector<int> coins={x, y, z};
        vector<vector<int>> dp(m , vector<int> (n+1 , -1));
        int ans=recur(dp , m-1, n, coins);
        if(ans<0) return 0;
        return ans;
    }
};


  
    

// { Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}  // } Driver Code Ends