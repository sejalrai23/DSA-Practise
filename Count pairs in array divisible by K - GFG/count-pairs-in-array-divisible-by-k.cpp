// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    long long countKdivPairs(int A[], int n, int K)
    {
        unordered_map<long long,long long> mp;
        long long ans=0;
        for(long long i=0;i<n;i++){
            long long rem= A[i]%K;
            long long need= K- rem;
            if(rem==0){
                ans+=mp[0];
            }else{
                ans+=mp[need];
            }
            mp[rem]++;
        }
        return ans;
        //code here
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;

		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

		int k;
		cin >> k;

        Solution ob;
		cout << ob. countKdivPairs(a, n , k) << "\n";



	}


	return 0;
}
  // } Driver Code Ends