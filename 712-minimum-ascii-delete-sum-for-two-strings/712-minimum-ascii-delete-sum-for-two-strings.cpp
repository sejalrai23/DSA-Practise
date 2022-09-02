class Solution {
public:
    int dp[1002][1002];
    int lcs(string& text1, string& text2 , int n,int m){
        if(n==0 || m==0){
            return 0;
        }
        if(dp[n][m]!=-1) return dp[n][m];
        if(text1[n-1]==text2[m-1]){
            // cout<<text1[n-1]<<endl;
          
            return dp[n][m]=int(text1[n-1]) + lcs(text1,text2,n-1,m-1);
        }else{
            return dp[n][m]=max(lcs(text1,text2,n-1,m),lcs(text1,text2,n,m-1));
        }
    }
    int minimumDeleteSum(string text1, string text2) {
        int n=text1.length(), m=text2.length();
        memset(dp,-1,sizeof(dp));
        int x=lcs(text1,text2,n,m);
        // cout<<x<<endl;
        int s1=0 ;
        for(auto it: text1){
            s1+=int(it);
        }
        for(auto it: text2){
            s1+=int(it);
        }
        // cout<<s1<<"-"<<s2<<"-"<<sum<<endl;
        return s1- 2*x;
    }
}; 
   