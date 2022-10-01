class Solution {
public:
    int dp[101];
    int recur(string s,int idx)
    {
        if(idx==s.size())
            return 1;
        if(s[idx]=='0')
            return 0;
        if(idx==s.size()-1)
            return 1;
        if(dp[idx]!=-1)
            return dp[idx];
        string temp=s.substr(idx,2);
        
        int op1=recur(s,idx+1);
        int op2=(stoi(temp)>=1 and stoi(temp)<=26)?recur(s,idx+2):0;
        
        return dp[idx]=op1+op2;
    }
    int numDecodings(string s) {
        
        memset(dp,-1,sizeof dp);
        return recur(s,0);
    }
};