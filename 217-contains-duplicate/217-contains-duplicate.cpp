class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> s;
        for(auto i:nums){
            s.insert(i);
        }
        // cout<<s.size()<<"-"<<nums.size();
        return s.size()!=nums.size();
            
        
    }
};