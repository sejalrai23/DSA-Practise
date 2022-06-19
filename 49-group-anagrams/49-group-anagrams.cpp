class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string , vector<string>> ump;
        for(int i=0;i<strs.size();i++){
            string temp=strs[i];
            sort(temp.begin(), temp.end());
            ump[temp].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for(auto it : ump){
            ans.push_back(it.second);
        }
        return ans;
        
    }
};