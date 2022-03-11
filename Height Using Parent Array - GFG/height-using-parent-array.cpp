// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int findHeight(int N, int arr[]){
        // code here
        map<int,int> m;
        for(int i=0;i<N;i++){
            if(arr[i]==-1){
                m[i]=1;
                break;
            }
        }
        for(int i=0;i<N;i++){
            if(arr[i]!=-1){
                auto it=m.find(arr[i]);
                m[i]=it->second+1;
            }
        }
        int ans=1;
        for(auto it:m){
            ans=max(ans,it.second);
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.findHeight(N, arr)<<"\n";
    }
    return 0;
}  // } Driver Code Ends