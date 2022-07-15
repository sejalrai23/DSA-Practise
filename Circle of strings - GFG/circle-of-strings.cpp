// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution
{
    public:
    
     void dfs(int node, vector<vector<int>> &graph, vector<int> &visited)
   {
       visited[node]=1;
       for(auto it: graph[node]){
           if(visited[it]==0){
               dfs(it,graph,visited);
           }
       }
       
   }
   int isCircle(int N, vector<string> A)
   {
       vector<vector<int>> graph(26);
       vector<int> ind(26,0),out(26,0);
       for(auto word: A){
           graph[word[0]-'a'].push_back(word.back()-'a');
           out[word.back()-'a']++;
           ind[word[0]-'a']++;
       }
       
       // To check indegree of each vertex is same as outdegree of the vertex
       for(int i=0; i<26; i++){
           if(ind[i]!=out[i]){
               return false;
           }
       }
       
       // To check whether it is connected or not
       vector<int> visited(26,0);
       bool flag=false;
       for(int node=0; node<26; node++){
           if(ind[node]!=0 && visited[node]==0){
               if(flag==true) return false;
               flag=true;
               dfs(node,graph,visited);
           }
       }
       
       return true;
   }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<string> A;
        string s;
        
        for(int i = 0;i < N; i++)
        {
            cin>>s;
            A.push_back(s);
        }
        
        Solution ob;
        cout<<ob.isCircle(N, A)<<endl;
    }
    return 0;
}  // } Driver Code Ends