// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct val{
	int first;
	int second;
};



int maxChainLen(struct val p[],int n);
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		val p[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i].first>>p[i].second;
		}
		
		cout<<maxChainLen(p,n)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/
/*You are required to complete this method*/
int maxChainLen(struct val p[],int n)
{
//Your code here
   sort(p,p+n,[](val a, val b){
        return a.second < b.second;
    });
    
    vector<int> dp(n,1);
    int maxi=0;
    for(int i=0;i<n ;i++){
        for(int j=0;j<i ;j++){
            if(p[i].first > p[j].second){
                dp[i]=max(dp[i], 1+dp[j]);
            }
            
        }
        maxi=max(maxi ,dp[i]);
    }
    
    return maxi;
}