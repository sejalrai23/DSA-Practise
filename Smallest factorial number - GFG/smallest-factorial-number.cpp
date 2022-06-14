// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
 int findNum(int n)
       {
           int l = 1, r = 5*n;
           while(l<r){
               int mid = (l+r)/2;
               int cnt = 0;
               for(int i=5;i<=mid;i *= 5){
                   cnt += (mid/i);
               }
               if(cnt<n) l = mid+1;
               else r = mid;
           }
           return l;
       }
};

// { Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Solution ob;
        cout <<ob.findNum(n) << endl;
    }
return 0;
}  // } Driver Code Ends