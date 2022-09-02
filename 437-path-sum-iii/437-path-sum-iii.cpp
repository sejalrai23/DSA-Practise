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
    int dfs(TreeNode* root , long long sum , int target){
        if(root==NULL ) return 0;
        
        if(!root->left && !root->right && sum+root->val==target){
            return 1;  
        }
        
        // if(sum>target) return 0;
        
        int lh=dfs(root->left , sum+root->val, target );
        int rh =dfs(root->right , sum+ root->val, target);  
        return (sum+root->val==target)+lh+rh;
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        return dfs(root ,0 , targetSum)+ pathSum(root->left , targetSum)+pathSum(root->right, targetSum);
    }
};