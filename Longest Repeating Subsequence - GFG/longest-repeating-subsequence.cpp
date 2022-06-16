// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
    	int lcs(string &a, string & b , int n , int m){
    	    int dp[n+1][m+1];
    	    
    	    for(int i=0;i<=n ;i++){
    	        for(int j=0;j<=m ;j++){
    	            if(i==0 || j==0) dp[i][j]=0;
    	            else {
    	                if(a[i-1]==b[j-1] && i!=j){
    	                 dp[i][j]=1+ dp[i-1][j-1];
    	               }else{
    	                   dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
    	               }
    	                
    	            }
    	               
    	        }
    	    }
    	    return dp[n][m];
    	}
		int LongestRepeatingSubsequence(string str){
		    int n= str.length();
		    return lcs(str, str , n ,n);
		    // Code here
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends