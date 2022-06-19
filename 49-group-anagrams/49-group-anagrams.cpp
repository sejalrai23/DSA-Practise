class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string , vector<int>> ump;
        for(int i=0;i<strs.size();i++){
            string temp=strs[i];
            sort(temp.begin(), temp.end());
            ump[temp].push_back(i);
        }
        vector<vector<string>> ans;
        for(auto it : ump){
            vector<string> res;
            for(auto x : it.second){
                res.push_back(strs[x]);
            }
            ans.push_back(res);
        }
        return ans;
        
    }
};