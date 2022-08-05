class Solution {
public:
int recur(vector<int>& nums , int target , int ind, int n, vector<vector<int>>& dp){
if(target==0) return 1;
if(ind>=n || target<0){
return 0;
}
// if(dp[ind][target]!=-1) return dp[ind][target];
int take=0,  notTake=0;
if(nums[ind]<=target){
take=  recur(nums , target-nums[ind] , ind , n, dp)+recur(nums ,target , ind+1 , n, dp) ;
}
else{
notTake=  recur(nums ,target , ind+1 , n, dp);
}
return take+notTake;
}
int combinationSum4(vector<int>& nums, int target) {
int n=nums.size();
vector<vector<int>> dp(n+1 , vector<int>(target+1 , -1));
return recur(nums , target , 0 , n, dp);
}
};
​
//this code doesnt consider duplicates
​
​
​