class Solution {
public:
    int dp[101][101];
    int solve(string s,int left,int k)
    {
        int p=k;
        if(s.size()-left<=k) return 0;
        if(dp[left][k]!=-1)
        return dp[left][k];
        int res=(k>0)?solve(s,left+1,k-1):1000;
        int c=1;
        for(int i=left+1;i<=s.size();i++)
        {
            res=min(res,solve(s,i,p)+1+(c>=100?3:(c>=10?2:(c>1?1:0))));
            if(i==s.size()) 
                break;
            else if(s[i]==s[left]) c++;
            else if(--p<0) break;
        }
        return dp[left][k]=res;
    }
    int getLengthOfOptimalCompression(string s, int k) 
    {
        memset(dp,-1,sizeof(dp));
        return solve(s,0,k);
        
    }
};