class Solution {
public:
    vector<vector<int>> generate(int numRows) {
         vector<vector<int>> ans;
         ans.push_back({1});
        
        for(int i=1;i<numRows; i++){
            int len= i+1;
            vector<int> dp(len , 1);
            for(int j=1;j< len-1 ; j++){
                dp[j]= ans[i-1][j-1] + ans[i-1][j];
            }
            ans.push_back(dp);
        }
        return ans;
    }
};