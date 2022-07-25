class Solution {
public:
    int dp[101][202];
    // int value;
    int recur(vector<int>& piles , int ind , int m){
        if(ind>=piles.size()) return 0;
        
        if(dp[ind][m]!=-1) return dp[ind][m];
        
        int sum=0;
        if(ind+ 2*m >= piles.size()){
            for(int i=ind;i<piles.size();i++){
                sum+=piles[i];
            }
            return dp[ind][m]=sum;
        }
        int value=INT_MIN;
        for(int i=1;i<=2*m ;i++){
            sum+=piles[ind+i-1];
            
            value=max(value, sum-recur(piles , ind+i, max(i , m)));
        }
        
        return dp[ind][m]=value;
        
        
        
    }
    int stoneGameII(vector<int>& piles) {
        // value=INT_MIN;
        int m=1;
        memset(dp , -1 , sizeof(dp));
        int val= recur(piles , 0 , m);
        int total=0;
        for(auto it: piles){
            total+=it;
        }
        int alice= (total+val)/2;
        return alice;
    }
};