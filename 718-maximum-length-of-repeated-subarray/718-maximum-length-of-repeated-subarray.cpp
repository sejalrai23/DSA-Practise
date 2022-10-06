class Solution {
public:
    int maxi=0;
    int recur(vector<int>&nums1 , vector<int>& nums2 , vector<vector<int>>& dp , int i , int j ,int n , int m ){
        if(i>=n || j>=m) return dp[i][j]=0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans1=0;
        recur(nums1,nums2 , dp , i, j+1, n , m);
        recur(nums1, nums2, dp , i+1, j, n , m);
        if(nums1[i]==nums2[j]){
            ans1=1+ recur(nums1, nums2, dp , i+1, j+1, n , m);
        }
        maxi=max(maxi , ans1);
        return dp[i][j]=ans1;
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(), m=nums2.size();
        vector<vector<int>> dp(n+1 , vector<int>(m+1, -1));
        recur(nums1, nums2, dp, 0 , 0, n , m);
        return maxi;
    }
};