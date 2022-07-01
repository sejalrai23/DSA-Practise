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
    int moves=0;
    int recur(TreeNode* root){
        if(root==NULL) return 0;
        int ls=recur(root->left);
        int rs=recur(root->right);
        moves+=abs(ls)+abs(rs);
        return root->val+ls+rs-1;
    }
    int distributeCoins(TreeNode* root) {
        recur(root);
        return moves;
    }
};