class Solution {
public:
vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
unordered_multiset<int> st(nums.begin(), nums.end());
for(int i = 0; i < operations.size(); i++) {
st.erase(operations[i][0]);
st.insert(operations[i][1]);
}
vector<int> ans(st.begin(), st.end());
return ans;
}
};
​
check this out 456ms only or use global array to reduce time complexity