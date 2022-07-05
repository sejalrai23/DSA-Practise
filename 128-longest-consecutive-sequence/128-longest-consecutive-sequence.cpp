class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        
        for(int i=0;i<nums.size();i++) s.insert(nums[i]);
        int maxi=0;
        for(auto it:s){
            int cnt=1;
            // cout<<s[i]<<endl;
            if(s.count(it - 1)) continue;
            while(s.count(it+1)){
                cnt++;
                it++;
            }
            maxi=max(cnt, maxi);
        }
        return maxi;
    }
};