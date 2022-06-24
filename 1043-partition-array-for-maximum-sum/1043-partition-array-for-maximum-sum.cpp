class Solution {
public:
    int recur(int i , vector<int>&arr , int k, vector<int>& dp){
         int n=arr.size();
        if(i==n) return dp[i]=0;
        if(dp[i]!=-1) return dp[i];
       
        int len=0, maxi=INT_MIN , maxAns=INT_MIN;
        for(int j=i;j< min(i+k , n);j++){
            len++;
            maxi=max(maxi,arr[j]);
            // cout<<maxi<<endl;
            int sum= len*maxi + recur(j+1, arr , k, dp);
            maxAns=max(maxAns, sum);
            
        }
        return dp[i]=maxAns;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n+1,-1);
        return recur(0, arr , k, dp);
    }
};


