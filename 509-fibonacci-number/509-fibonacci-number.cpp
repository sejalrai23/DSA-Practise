class Solution {
public:
    int dp[32];
    int fibo(int n){
        if(n<2) return dp[n]=n;
        if(dp[n]!=-1) return dp[n];
        return dp[n]=fibo(n-1)+fibo(n-2);
    }
    int fib(int n) {
        if(n==0) return 0;
        memset(dp, -1, sizeof(dp));
        fibo(n);
        return dp[n];
    }
};