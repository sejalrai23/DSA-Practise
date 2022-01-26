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
    void Inorder(TreeNode* root , vector<int>& v){
        if(root==NULL){
            return ;
        }
        Inorder(root->left, v);
        v.push_back(root->val);
        Inorder(root->right, v);
        return ;
        
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> v1;
        Inorder(root1,v1);
        Inorder(root2, v1);
        
        sort(v1.begin(), v1.end());
        
        return v1;
        
    }
};