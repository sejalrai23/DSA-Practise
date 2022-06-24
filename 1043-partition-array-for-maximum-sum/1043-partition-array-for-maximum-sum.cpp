class Solution {
public:
    int recur(int i , vector<int>&arr , int k, vector<int>& dp){
         int n=arr.size();
        if(i==n) return 0;
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


// class Solution {
// public:
//     int getans(int ind,vector<int>& arr,int k,vector<int>&dp){
//         int n=arr.size();
//         if(ind==n) return dp[ind]=0;
//         if(dp[ind]!=-1) return dp[ind];
//         int len=0;
//         int maxi=INT_MIN;
//         int ans=INT_MIN;
//         for(int i=ind;i<min(ind+k,n);i++){
//             len++;
//             maxi=max(maxi,arr[i]);
//             int sum=len*maxi+getans(i+1,arr,k,dp);
//             ans=max(ans,sum);
//         }
//         return dp[ind]=ans;
//     }
//     int maxSumAfterPartitioning(vector<int>& arr, int k) {
//         int n=arr.size();
//         vector<int>dp(n+1,-1);
//         return getans(0,arr,k,dp);
//     }
// };