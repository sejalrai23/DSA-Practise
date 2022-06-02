class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size();i++){
            for(int j=i;j<matrix[0].size();j++){
                 swap(matrix[j][i],matrix[i][j]);
            }
             for(int j=0;j<matrix.size()/2;j++){
                swap(matrix[i][j],matrix[i][matrix.size()-j-1]);
            }
        }

    }
};