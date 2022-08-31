class Solution {
public:
    int m,n;
    
    bool s(vector<vector<bool>>& ocean, int i, int j, vector<vector<int>>& mat){
        
        if (i<0 || j<0 || i==m || j==n || mat[i][j]==-1) return false;
        if (ocean[i][j]) return true;
        
        int k = mat[i][j];
        mat[i][j]=-1;
        if (i>0 && mat[i-1][j]<=k)   ocean[i][j] = ocean[i][j] || s(ocean,i-1,j,mat);
        if (j>0 && mat[i][j-1]<=k)   ocean[i][j] = ocean[i][j] || s(ocean,i,j-1,mat);
        if (i<m-1 && mat[i+1][j]<=k) ocean[i][j] = ocean[i][j] || s(ocean,i+1,j,mat);
        if (j<n-1 && mat[i][j+1]<=k) ocean[i][j] = ocean[i][j] || s(ocean,i,j+1,mat);
    
        mat[i][j]=k;
        return ocean[i][j];
        
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& mat) {
        m = mat.size();
        n = mat[0].size();
        vector<vector<bool>> pac(m, vector<bool> (n,false));
        vector<vector<bool>> atl(m, vector<bool> (n,false));
        for (int i=0; i<m; i++){
            pac[i][0]=true;
            atl[i][n-1]=true;
        }
        for (int i=0; i<n; i++){
            pac[0][i]=true;
            atl[m-1][i]=true;
        }
        vector<vector<int>> res;
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (s(pac,i,j,mat) && s(atl,i,j,mat)) res.push_back({i,j});
            }
        }return res;
    }
};