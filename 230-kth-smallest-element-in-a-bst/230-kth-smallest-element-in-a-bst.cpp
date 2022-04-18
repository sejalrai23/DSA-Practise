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
    priority_queue<int> pq;
    void inorder(TreeNode*root, int k){
        if(root==NULL){
            return;
        }
        inorder(root->left,k);
        pq.push(root->val);
        if(pq.size()>k){
            pq.pop();
        }
        inorder(root->right, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        inorder(root,k);
        return pq.top();

        
    
    }
};