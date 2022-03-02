class Solution {
public:
    void combinations(int ind , int k , int n , vector<vector<int>>& ans , vector<int>& ds){
        if(ds.size()==k){
            if(n==0){
                ans.push_back(ds);
                return;
            }
        }
        for(int i=ind ; i<=9;i++){
            if(i>n){
                break;
            }
            ds.push_back(i);
            combinations(i+1,k, n-i, ans, ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> ds;
        vector<vector<int>> ans;
        combinations(1,k,n,ans,ds);
        return ans;
        
    }
};