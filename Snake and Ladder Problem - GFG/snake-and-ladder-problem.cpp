// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minThrow(int N, int arr[]){
        // code here
        int st=1;
        queue<int> pq;
        pq.push(st);
        int moves=0;
        vector<int> m={1,2,3,4,5,6};
        map<int,int> mp;
        for(int i=0;i<2*N ;i+=2){
            mp[arr[i]]=arr[i+1];
        }
        
        while(!pq.empty()){
            moves++;
            int s=pq.size();
            for(int i=0;i<s;i++){
                int curr=pq.front();
                pq.pop();
                for(int x: m){
                    int next= x+curr;
                    if(mp.find(next)!=mp.end()) next=mp[next];
                    if(next>30) continue;
                    if(next==30) return moves;
                    pq.push(next);
                }
            }
        }
        return -1;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[2*N];
        for(int i = 0;i < 2*N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.minThrow(N, arr)<<"\n";
    }
    return 0;
}  // } Driver Code Ends