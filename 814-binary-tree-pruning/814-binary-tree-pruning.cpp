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
    bool zeroNode(TreeNode* & root,bool left1 , bool right1){
        if(root==NULL) return true;
        bool left = zeroNode(root->left, left1 , right1);
        bool right =zeroNode(root->right,left1 , right1);
        
       if(left) root->left=NULL;
        if(right) root->right=NULL;
        if(root->val==0){
            return (true && (left && right));
        }
        
      
        return false;
    }
    TreeNode* pruneTree(TreeNode* root) {
        
        bool ans=zeroNode(root, true , true);
        if(ans) return {};
        return root;
    }

};