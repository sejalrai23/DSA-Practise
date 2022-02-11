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
    bool isValid(TreeNode* root , int val){
        if(root==NULL){
            return true;
        }
        if(root->val!=val){
            return false;
        }
        return isValid(root->left, val) && isValid(root->right , val);
        
    }
    bool isUnivalTree(TreeNode* root) {
        int val=root->val;
      
        return isValid(root, val);
    }
};