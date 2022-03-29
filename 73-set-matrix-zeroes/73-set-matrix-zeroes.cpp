class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
       // int vis[mat.size()][mat[0].size()];
       //  memset(vis,0,size(vis));
        vector<vector<int>> arr;
        int n=mat.size(), m=mat[0].size();
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==0){
                    arr.push_back({i,j});
                }
            }
        }
        for(auto it : arr){
            for(int i=0 ; i<n ; i++){
                mat[i][it[1]]=0;
            }
            for(int j=0;j<m ;j++){
                mat[it[0]][j]=0;
            }
        }
        
        
    }
};