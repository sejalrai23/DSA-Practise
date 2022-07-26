class Solution {
public:
    vector<int> ans;
    void dfs(map<int , vector<int>> &mp, map<int, int>& vis , int node){
        vis[node]=1;
        ans.push_back(node);
        
        for(auto x:mp[node]){
            if(!vis[x]){
                dfs(mp , vis , x);
            }
        }
    }
    
    vector<int> restoreArray(vector<vector<int>>& vec) {
        int n=vec.size()+1;
        map<int, vector<int>> mp;
        
        for(auto it: vec){
            mp[it[0]].push_back(it[1]);
            mp[it[1]].push_back(it[0]);
        }
        
        map<int , int> vis;
        int node;
        for(auto it: mp){
        if(it.second.size()==1){
            node=it.first;
            break;
        }
        }
        dfs(mp , vis , node);
        return ans;
    }
};