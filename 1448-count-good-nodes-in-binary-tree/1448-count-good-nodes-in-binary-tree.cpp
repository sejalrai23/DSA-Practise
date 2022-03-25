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
    void count(TreeNode* root ,int val ){
        if(root==NULL){
            return;
        }
       
        if(root->val>=val){
            // cout<<root->val <<"-"<<val<<endl;
            cnt++;
        }
        // max(val,root->val);
        count(root->left,max(val,root->val));
        count(root->right,max(val,root->val));
    }
    int goodNodes(TreeNode* root) {
        int val= INT_MIN;
        count(root, val);
        return cnt;
    }
};