class Solution {
public:
    // vector<int> indices;                                                 
    vector<bool> visited;
    vector<vector<int>> adjList;
    // string indiceString;                                                 
    void dfs(string &s,int n,vector<int>& indices , string & indiceString)                                           
    {
        visited[n]=true;
        indices.push_back(n);
        indiceString+=s[n];
        for(auto i:adjList[n])
            if(!visited[i])
               dfs(s,i, indices , indiceString);
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) 
    {
        adjList.resize(s.length());
        visited.resize(s.length(),false);
        for(auto v:pairs)                           
            adjList[v[0]].push_back(v[1]),adjList[v[1]].push_back(v[0]);
        for(int i=0;i<s.length();i++)
            if(!visited[i])
            {
                string indiceString="";    
                vector<int> indices;
                // indices.clear();                           
                dfs(s,i,indices , indiceString);
                sort(indiceString.begin(),indiceString.end());                    
                sort(indices.begin(),indices.end());                                            
                for(int i=0;i<indices.size();i++)          
                    s[indices[i]]=indiceString[i];
            }
        return s;
    }
};