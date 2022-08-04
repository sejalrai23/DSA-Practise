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
// class Solution {
// public:
//     vector<int> postorderTraversal(TreeNode* root) {
        
//     }
// };
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(root==NULL) return {};
        vector<int> post;
        stack<TreeNode*> s;
        // TreeNode* curr=root;
        s.push(root);
        while(!s.empty()){
        TreeNode* node=s.top();
        s.pop();
        post.push_back(node->val);
            if(node->left) s.push(node->left);
            
            if(node->right) s.push(node->right);
            
        
        }
        reverse(post.begin(), post.end());
        return post;
        
    }
};