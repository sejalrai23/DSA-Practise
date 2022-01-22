class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> in(n,0);
        vector<int> ans;
        for(int i=0;i<edges.size();i++){
            in[edges[i][1]]++;
            
        }
        for(int i=0;i<in.size();i++){
            if(in[i]==0){
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};