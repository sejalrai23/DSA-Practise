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
    int findHeight(TreeNode* root){
        if(root==NULL) return 0;
        int lh=findHeight(root->left);
        int rh=findHeight(root->right);
        return 1+ max(lh , rh);
    }
    TreeNode* findNode(TreeNode* root , int lev){
        if(root==NULL) return NULL;
        TreeNode* lh= findNode(root->left , lev-1);
        TreeNode* rh= findNode(root->right , lev-1);
        
        if(lev==1){
            if(root->left){
                return root->left;
            }else if(root->right){
                return root->right;
            }
        }
        
        if(lh)return lh;
        else if(rh) return rh;
        return NULL;
        
    }
    int findBottomLeftValue(TreeNode* root) {
        if(root==NULL) return 0;
        int maxi=findHeight(root);
        TreeNode* ans= findNode(root , maxi-1);
        // if(ans) return ans->val;
        return ans!=NULL ? ans->val : root->val;
    }
};