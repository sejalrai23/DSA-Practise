class Solution {
public:
    bool static comp(const vector<int>& v1, const vector<int>& v2){
        return v1[1] < v2[1];
    }
        
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), comp);
        int n=pairs.size();
        int maxi=0;
        vector<int> dp(n ,1);
        for(int i=0;i<n ;i++){
            for(int j=0;j<i ; j++){
                if(pairs[i][0] > pairs[j][1]){
                    dp[i]=max(dp[i], 1+dp[j]);
                }
            }
            maxi=max(maxi, dp[i]);
        }
        return maxi;
        
    }
};