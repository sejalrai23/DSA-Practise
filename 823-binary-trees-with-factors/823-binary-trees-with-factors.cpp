class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        unordered_map<int , int> mp;
        int mod =1e9+7;
        int n= arr.size();
        vector<long long> dp(n , 1);
        sort(arr.begin(), arr.end());
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]=i;
        }
        
        for(int i=0;i< n ;i++){
            for(int j=0;j<i ;j++){
                if(arr[i]%arr[j]==0){
                    int right = arr[i]/arr[j];
                    
                    if(mp.find(right)!= mp.end()){
                        dp[i]+=(dp[j] * dp[mp[right]])%mod;
                    }
                }
            }
        }
        long long cnt=0;
        for(auto it: dp){
            cnt+=it;
            cnt%=mod;
        }
        
        return cnt;
    }
};