// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
//User function template 

class Solution{
  public:
    // s : given string
    // return the expected answer
    int fun(string &s) {
        //code here
       int long a = 0;
       int long ab = 0;
       int long abc = 0;
       int mod = 1e9+7;
       for(auto &e : s)
       {
           if(e=='a')
           {
               a = (2*a+ 1) %mod;
           }
           else if(e=='b')
           {
               ab = (2*ab + a) %mod;
           }
           else if(e=='c')
           {
               abc = (2*abc + ab)%mod;
           }
          
       }
        return abc %mod;


    }
};

// { Driver Code Starts.
 
int main()
 {
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        Solution obj;
        cout<<obj.fun(s)<<endl;
    }
	return 0;
}  // } Driver Code Ends