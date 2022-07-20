class Solution {
public:
    bool checkPath(int u, int v, vector<vector<int>> &graph, vector<int> &vis)
    {
        
        vis[u] = 1;
        for(auto vx : graph[u])
        {
            if(vx == v)
                return true;
            if(!vis[vx])
                if(checkPath(vx, v, graph, vis) == true)
                    return true;
        }
        return false;
    }
    bool equationsPossible(vector<string>& equations) {
        
        string s;
        int i, j, k, u, v, e = equations.size();
        
        vector<int> vis(26, 0);
        vector<pair<int,int>> noPath;
        vector<vector<int>> graph(26);
    
        for(i=0;i<e;i++)
        {
            s = equations[i];
            u = s[0] - 'a';
            v = s[3] - 'a';
            
            if(s[1] == '!')
            {
                if(s[0] == s[3])
                    return false;
                noPath.push_back({u,v});
            }
            else
            {
                graph[u].push_back(v);
                graph[v].push_back(u);
            }
        }
        for(auto p : noPath)
        {
            u = p.first;
            v = p.second;
            for(i=0;i<26;i++)
                vis[i] = 0;
            if(checkPath(u, v, graph, vis) == true)
                return false;
        }
        return true;
    }
};