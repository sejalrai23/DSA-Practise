class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        vector<int> ans;
        map<int ,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        for(auto it : m){
            if(it.second==1){
                if(m.find(it.first+1)== m.end() && m.find(it.first-1)==m.end()){
                    ans.push_back(it.first);
                }
            }
        }
        return ans;
    }
};