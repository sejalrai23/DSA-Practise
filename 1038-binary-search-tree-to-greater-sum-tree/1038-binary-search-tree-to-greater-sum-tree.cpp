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
    vector<int> in;
    void inorder(TreeNode* root,int &cnt){
        if(root==NULL){
            return;
        }
        inorder(root->right,cnt);
        cnt+=root->val;
        root->val=cnt;
        inorder(root->left,cnt);    
    }
    TreeNode* bstToGst(TreeNode* root) {
        int prefSum=0;
        int cnt=0;
        inorder(root,cnt);
        return root;
        
    }
};