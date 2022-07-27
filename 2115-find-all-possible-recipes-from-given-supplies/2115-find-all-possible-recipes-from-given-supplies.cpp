class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
    
        vector<string> res;
        
        unordered_map<string,int> in;
        for(auto rec : recipes) in[rec] = 0;
        
	
        unordered_map<string,vector<string>> g;
        

        unordered_set<string> st;
        for(auto sup : supplies) st.insert(sup);
    
        for(int i=0;i<recipes.size();i++)
        {
            for(int j=0;j<ingredients[i].size();j++)
            {
                if(st.find(ingredients[i][j]) == st.end())
                {        in[recipes[i]]++;
                    g[ingredients[i][j]].push_back(recipes[i]);
                }
            }
        }
        
        queue<string> q;
        for(auto it : in)
        {
            if(it.second == 0)
                q.push(it.first);
        }
        
        while(!q.empty())
        {
            int c = q.size();
            for(int i=0;i<c;i++)
            {
                auto rec = q.front(); q.pop();
                res.push_back(rec);
                for(auto child : g[rec])
                {
                    in[child]--;
                    if(in[child] == 0) q.push(child);
                }
            }
        }
        
        return res;
    }
};