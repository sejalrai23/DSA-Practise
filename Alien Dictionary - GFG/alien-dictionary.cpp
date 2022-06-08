// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    void findTopoSort(stack<int> &s,vector<vector<int>>&adj , vector<int>& vis , int node ){
        vis[node]=1;
        for(auto it: adj[node]){
            if(!vis[it]){
                findTopoSort(s,adj,vis,it);
            }
        }
        s.push(node);
    }
    string findOrder(string dict[], int N, int K) {
        //code here
        stack<int> s;
        vector<int> vis(K, 0);
        vector<vector<int>> adj(K);
        for(int i=0;i<N-1 ; i++){
            if(dict[i]==dict[i+1]) continue;
            else{
                int j=0, k=0;
                while(j<dict[i].length() && k<dict[i+1].length()){
                    if(dict[i][j]!=dict[i+1][k]){
                        adj[dict[i][j]-'a'].push_back(dict[i+1][k]-'a');
                        break;
                    }
                    j++;
                    k++;
                    }
                }
            }
            
            for(int i=0;i<K;i++){
                if(!vis[i]){
                    findTopoSort(s, adj , vis ,i);
                }
            }
            string ans="";
            while(!s.empty()){
                ans+=s.top()+'a';
                s.pop();
            }
            // cout<<ans<<endl;
            return ans;
        }
    
};

// { Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends