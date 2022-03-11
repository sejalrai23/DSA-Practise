class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& inter) {
        vector<vector<int>> ans;
        if(inter.size()<=1){
            return inter;
        }
        sort(inter.begin(),inter.end());
        ans.push_back(inter[0]);
        for(int i=1;i<inter.size();i++){
            if(ans.back()[1]>=inter[i][0]) ans.back()[1]=max(ans.back()[1],inter[i][1]);
            else{
                ans.push_back(inter[i]);
            }
        }
        return ans;
    }
};