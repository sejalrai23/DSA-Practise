class Solution {
public:
    bool divisorGame(int n) {
        int dp[n+1];
        dp[0]=0;
        dp[1]=0;
        
        for(int i=2;i<=n;i++){
            if(dp[i-1]==0){
                dp[i]=1;
            }else{
                dp[i]=0;
            }
            // cout<<i<<"-"<<dp[i]<<endl;
        }
        
        return dp[n];
    }
};