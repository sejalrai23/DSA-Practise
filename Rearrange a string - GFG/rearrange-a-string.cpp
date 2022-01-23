// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
  public:
    string arrangeString(string str)
    {
        //code here.
        int sum=0;
        string ans="";
        for(int i=0;i<str.length();i++){
            if(isdigit(str[i])){
                sum+=(str[i]-'0');
            }else{
                ans+=str[i];
            }
        }
       sort(ans.begin(),ans.end());
       ans+=to_string(sum);
       return ans;
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout <<ob.arrangeString(s) << endl;
    }
return 0;
}

  // } Driver Code Ends