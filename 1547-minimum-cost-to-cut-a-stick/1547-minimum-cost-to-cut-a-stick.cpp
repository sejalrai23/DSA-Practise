class Solution {
public:
    int recur(vector<int>& cuts , vector<vector<int>>& dp , int i , int j){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mini=INT_MAX;
        for(int k=i ;k<=j ;k++){
            int cost= cuts[j+1]-cuts[i-1] + recur(cuts , dp , i , k-1) + recur(cuts , dp , k+1 , j);
            mini=min(mini,cost);
        }
        return dp[i][j]=mini;
    }
    int minCost(int n, vector<int>& cuts) {
        int c=cuts.size();
        vector<vector<int>> dp(c+1 , vector<int>(c+1 , -1));
        cuts.push_back(n);  // length because last cut is at index n
        cuts.insert(cuts.begin(), 0) ;// 0 because first cut is at index 0;
        sort(cuts.begin(), cuts.end());
        return recur(cuts, dp , 1 , c);
            
    }
};