class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        ans.push_back(1);
        
        for(int i=1;i<=rowIndex ;i++){
            int len= i+1;
            vector<int> dp(len, 1);
            for(int j=1;j<len-1;j++){
                dp[j]= ans[j-1]+ ans[j];
            }
            ans=dp;
        }
        return ans;
    }
};