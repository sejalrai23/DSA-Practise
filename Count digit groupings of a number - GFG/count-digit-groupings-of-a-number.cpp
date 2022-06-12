// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	
	int recur(string & str, int ind , int sum , vector<vector<int>>& dp){
	    if(ind==str.size()){
	        return 1;
	    }
	    if(dp[ind][sum]!=-1) return dp[ind][sum];
	    int tmp=0, ans=0;
	    for(int i=ind ;i<str.size();i++){
	       
	        tmp+=str[i]-'0';
	        if(tmp>=sum){
	           // cout<<"**"<<i<<"**"<<endl;
	            ans+=recur(str, i+1, tmp , dp);
	        }
	       // cout<<ans<<endl;
	    }
	    return dp[ind][sum]=ans;
	}
	int TotalCount(string str){
	    // Code here
	    int n=str.size();
	    vector<vector<int>> dp(n , vector<int>(1000,-1));
	    return recur(str, 0, 0, dp);
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution ob;
		int ans = ob.TotalCount(str);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends