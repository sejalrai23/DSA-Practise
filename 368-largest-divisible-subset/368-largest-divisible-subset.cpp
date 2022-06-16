class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n , 1) , hash(n) ;
        int maxi=0, last=0;
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n ;i++ ){
            hash[i]=i;
            for(int j=0;j<i ;j++){
                if(nums[i]%nums[j]==0 && dp[i]< dp[j]+1){
                    dp[i]=dp[j]+1;
                    hash[i]= j;
                }
            }
            if(dp[i] > maxi){
                maxi=dp[i];
                last=i;
            }
        }
        vector<int> ans;
        ans.push_back(nums[last]);
        
        while(hash[last]!=last){
            last=hash[last];
            ans.push_back(nums[last]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};