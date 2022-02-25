class Solution {
public:
    
    int climbStairs(int n) {
        int dp[n+1];
        // if(n==1 || n==2){
        //     return dp[n-1];
        // }
        dp[0]=1;
        dp[1]=2;
        for(int i=2;i<n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        // findCombi(0,n,cnt);
        return dp[n-1];
    }
};