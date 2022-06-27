// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    vector<int> changeBits(int N) {
        // code here
        // unsigned int number=N;
        int mask = log2(N)+1;
        // cout<<mask<<endl;
        int num=pow(2,mask)-1;
        // cout<<num<<endl;
        int convertedNum= N | num;
        return {abs(N-convertedNum),convertedNum};
        // return {0, 0};
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        Solution ob;
        auto ans = ob.changeBits(N);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}  // } Driver Code Ends