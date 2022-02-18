class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combine(int n, int k) {
        vector<int> nums;
        vector<int> vec;

         for(int i=1;i<=n;i++){
             nums.push_back(i);
             
         }
        helper(nums,0,0,k,n,vec);
         return ans;
        
    }
    
    void helper(vector<int>& nums , int idx , int i,int k , int n,vector<int> vec){
        if(idx==k){
            ans.push_back(vec);
            return;
        }
        while(i<n){
            vec.push_back(nums[i]);
            helper(nums , idx+1,i+1,k,n,vec);
            vec.pop_back();
            i++;
        }
    }
};