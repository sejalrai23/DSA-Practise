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
    int maxi=INT_MIN;
    void dfs(TreeNode* root , int & cnt , int val){
        if(root==NULL) return ;
        cnt= max(abs(val- root->val), cnt);
        dfs(root->left, cnt , val);
        dfs(root->right, cnt , val);
    }
    
    void FinalDfs(TreeNode* root ){
        if(root==NULL) return ;
        int diff=0;
        dfs(root , diff, root->val);
        maxi=max(maxi, diff);
        FinalDfs(root->left);
        FinalDfs(root->right);
    }
    int maxAncestorDiff(TreeNode* root) {
        FinalDfs(root);
        return maxi;
    }
};