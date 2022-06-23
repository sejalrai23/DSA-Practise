class Solution {
public:
    int recur(vector<int>& nums , int i , int j , vector<vector<int>>& dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int maxi=INT_MIN;
        for(int ind=i;ind<=j; ind++){
           int val=nums[ind];
           int  coins= nums[i-1]*nums[ind]*nums[j+1] + recur(nums , i , ind-1, dp) + recur(nums , ind+1 , j , dp);
            maxi=max(maxi,coins);
        }
        return dp[i][j]=maxi;
    }
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>> dp(n+1 , vector<int>(n+1 , -1));
        return recur(nums , 1 , n , dp);
        
    }
};










