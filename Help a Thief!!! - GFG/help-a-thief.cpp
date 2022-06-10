// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int maxCoins(int A[], int B[], int T, int N) {
        if(T==0) return 0;
        vector<pair<int,int>> v;
        int ans=0;
        for(int i=0;i<N ; i++){
            v.push_back({B[i], A[i]});
        }
        sort(v.begin(),v.end());
        for(int i=N-1;i>=0 && T!=0;i--)
        {
            int no_of_plates=v[i].second;
            int no_of_coins=v[i].first;
            // cout<<no_of_plates << "-"<<no_of_coins<<endl;
            if(no_of_plates<T)
            {
                ans+=no_of_plates*no_of_coins;
                T-=no_of_plates;
            }
            else
            {
                ans+=T*no_of_coins;
                T=0;
            }
        }
        return ans;
        // code here
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int T,N;
        cin>>T>>N;
        
        int A[N], B[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];
        for(int i=0; i<N; i++)
            cin>>B[i];

        Solution ob;
        cout << ob.maxCoins(A,B,T,N) << endl;
    }
    return 0;
}  // } Driver Code Ends