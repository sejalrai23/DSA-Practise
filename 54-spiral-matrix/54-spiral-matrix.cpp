class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m= matrix[0].size(), n=matrix.size();
        int left=0, right=m-1, top=0, bottom=n-1;
        int dir=1;
        while(left<=right && top<=bottom){
            if(dir==1){
                for(int i=left; i<=right;i++){
                    ans.push_back(matrix[top][i]);
                }
                dir=2;
                top++;
            }else if(dir==2){
                for(int i=top;i<=bottom ;i++){
                    ans.push_back(matrix[i][right]);
                }
                right--;
                dir=3;
            }else if(dir==3){
                for(int i=right ;i>=left ; i--){
                    ans.push_back(matrix[bottom][i]);
                }
                dir=4;
                bottom--;
            }
            else if(dir==4){
                for(int i=bottom;i>=top;i--){
                    ans.push_back(matrix[i][left]);
                }
                dir=1;
                left++;
            }
        }
        return ans;
        
    }
};