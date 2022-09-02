/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> ans;
    void dfs(TreeNode* root , int sum , int target , vector<int> ds){
        if(root==NULL ) return;
        
        if(!root->left && !root->right && sum+root->val==target){
           ds.push_back(root->val);
           ans.push_back(ds);
            return;  
        }
        
        
        
        
        ds.push_back(root->val);
        dfs(root->left , sum+root->val, target , ds);
        dfs(root->right , sum+ root->val, target , ds);
        ds.pop_back();
      
      
       
        
       
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> ds;
        dfs(root , 0 , targetSum , ds);
        return ans;
    }
};