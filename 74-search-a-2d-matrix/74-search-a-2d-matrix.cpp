class Solution {
public:
    bool BinarySearch(vector<int>& v,int st,int end,int target){
        while(st<=end){
            int mid= (st+end)/2;
            if(v[mid]==target){
                return true;
            }else if(v[mid]<target){
                st=mid+1;
            }else{
                end=mid-1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=0;
        for(int j=0;j<matrix.size();j++){
             // cout<<matrix[j][0]<<endl;
            if(matrix[j][0]==target){
                return true;
            }
            else if(matrix[j][0]>target){
                row=j;
                break;
            }else{
                row++;
            }
        }
        if(row==0){
            return false;
        }
        return BinarySearch(matrix[row-1],0,matrix[row-1].size()-1,target);
        
    }
};