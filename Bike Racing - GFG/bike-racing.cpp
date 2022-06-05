// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    long checkHour(long H[], long A[],long M, long L,long N , long hour ){
        long ans=0;
        for(long i=0;i<N ; i++){
            if((hour*A[i] + H[i]) >= L){
                ans+=(hour*A[i]+H[i]);
            }
        }
    
        return ans;
    }
    long buzzTime(long N, long M, long L, long H[], long A[])
    {
        // code here
        long st=0 ,res=0, end= max(L,M);
        while(st<=end){
            long mid = st + (end-st)/2;
            long ans=checkHour(H, A, M , L ,N , mid);
            // cout<<ans<<endl;
            if(ans>=M){
                res=mid;
                end=mid-1;
            }else{
                st=mid+1;
            }
        }
        return res;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long N, M, L;
        cin>>N>>M>>L;
        long H[N], A[N];
        for(long i = 0;i < N;i++) 
            cin>>H[i]>>A[i];
        
        Solution ob;
        cout<<ob.buzzTime(N, M, L, H, A)<<"\n";
    }
    return 0;
}  // } Driver Code Ends