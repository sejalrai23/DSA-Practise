class Solution {
public:
    void combination(int i,int target , vector<int>& can,vector<vector<int>>& ans ,vector<int>& ds){
        if(i==can.size()){
            if(target==0){
                ans.push_back(ds);
                
            }return;
        }
        if(can[i]<=target){
            ds.push_back(can[i]);
            combination(i,target-can[i],can,ans,ds);
            ds.pop_back();
            
        }
        combination(i+1,target,can,ans,ds);
        
    }
    vector<vector<int>> combinationSum(vector<int>& can, int target) {
        vector<int> ds;
        vector<vector<int>> ans;
        combination(0,target,can,ans,ds);
        return ans;
        
    }
};