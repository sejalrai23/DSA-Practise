class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        map<int , vector<int>> mp;
         map<int , vector<int>> mp1;
        int n= mat.size() , m= mat[0].size();
        
        int col=0, row=0;
        for(int i=0;i<m;i++){
            int x=0 , y=i;
            while(x<n && y<m){
                mp[col].push_back(mat[x][y]);
                x++;
                y++;
            }
            sort(mp[col].begin(), mp[col].end());
            col++;
        }
        
        for(int i=1;i<n;i++){
            int x=i , y=0;
            while(x<n && y<m){
                mp1[row].push_back(mat[x][y]);
                x++;
                y++;
            }
            sort(mp1[row].begin(), mp1[row].end());
            row++;
        }
        col=0; row=0;
        for(int i=0;i<m;i++){
            int x=0 , y=i , k=0;
            while(x<n && y<m){
                mat[x][y]= mp[col][k];
                k++;
                x++;
                y++;
            }
            col++;
        }
        
        for(int i=1;i<n;i++){
            int x=i , y=0 , k=0;
            while(x<n && y<m){
                mat[x][y]= mp1[row][k];
                k++;
                x++;
                y++;
            }
            row++;
        }
        
        return mat;
        
        
        
    }
};