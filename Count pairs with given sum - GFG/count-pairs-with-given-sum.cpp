// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        // code here
        int cnt=0;
        map<int,int> m;
        for(int i=0;i<n;i++){
            m[arr[i]]++;
        }
        for(int i=0;i<n;i++){
            auto it = m.find(k-arr[i]);
            // cout<<it->first<<"-"<<it->second<<endl;
            m[arr[i]]--;
            if(it!=m.end()){
                cnt+=(it->second) ;
                // cout<<cnt<<endl;
                
            }
        }
        return cnt;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getPairsCount(arr, n, k);
        cout << ans << "\n";
    }
    
    return 0;
}  // } Driver Code Ends