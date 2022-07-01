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
    int diff(TreeNode* root , int mini, int maxi){
        if(root==NULL) return(maxi-mini);
        mini=min(mini,root->val);
        maxi=max(maxi, root->val);
        int lh= diff(root->left , mini , maxi);
        int rh= diff(root->right , mini, maxi);
        return max(lh , rh);
    }
    int maxAncestorDiff(TreeNode* root) {
        return diff(root , INT_MAX , INT_MIN);
    }
};