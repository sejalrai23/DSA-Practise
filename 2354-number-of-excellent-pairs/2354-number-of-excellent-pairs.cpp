class Solution {
public:
//     int getSetBits(int num){
        
//     }
    long long countExcellentPairs(vector<int>& nums, int k) {
        map<int, int> mp;
        
        for(int i=0;i<nums.size();i++){
            if(!mp[nums[i]]){
                mp[nums[i]]= __builtin_popcount (nums[i]);
            }
        }
        
        map<int, int> cnt;
        for(auto it: mp){
            cnt[it.second]++;
        }
        
        long long ans=0;
         for(auto i:cnt){
            for(auto& j:cnt){
                if((i.first+j.first)>=k){                
                    ans+= (i.second*j.second);
                }
            }
        }
        return ans;
    }
};