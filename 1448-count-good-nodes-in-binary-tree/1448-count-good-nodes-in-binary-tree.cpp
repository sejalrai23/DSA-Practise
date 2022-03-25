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
    int cnt=0;
    int count(TreeNode* root ,int val ){
        if(root==NULL){
            return 0;
        }
       
        if(root->val>=val){
            cnt++;
        }
        return cnt+  count(root->left,max(val,root->val))+count(root->right,max(val,root->val));
    }
    int goodNodes(TreeNode* root) {
        int val= INT_MIN;
        count(root, val);
        return cnt;
    }
};