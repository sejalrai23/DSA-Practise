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
   int sum=0;
    void dfs(TreeNode* root , string s){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL){
            s+=to_string(root->val);
            sum+=stoi(s);
            return;
            
        }
        
        dfs(root->left , s+to_string(root->val));
         dfs(root->right , s+to_string(root->val));
        return ;
    }
    int sumNumbers(TreeNode* root) {
        string s="";
        dfs(root , s);
        // for(auto it: ans){
        //     cout<<it<<endl;
        // }
        return sum;
    }
};