class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int st=matrix[0][0] , end = matrix[n-1][n-1];
        while(st<=end){
            int mid=(st+end)/2;
            int cnt=0;
            for(int i=0;i<matrix.size();i++){
                for(int j=0;j<matrix[0].size();j++){
                      if(matrix[i][j]<=mid){
                        cnt++;
                    }
                }
            }
            if(cnt>=k){
                end=mid-1;
            }else{
                st=mid+1;
            }
        }
        return st;
        
        
        
    }
};