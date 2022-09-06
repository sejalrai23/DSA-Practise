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
    vector<TreeNode*> trees;
    map<int, int> mp;
    
    TreeNode* findandDelete(TreeNode* & root){
        if(root==NULL) return NULL;
        TreeNode* left= findandDelete(root->left );
        TreeNode* right= findandDelete(root->right);
        
        if(left) {
            trees.push_back(root->left);
            root->left=NULL;
        }
        if(right){
            trees.push_back(root->right);
            root->right=NULL;

        }
        
        if(mp[root->val]){
            mp[root->val]=0;
            return root;
        }
        return NULL;
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        
        for(auto it: to_delete){
            mp[it]=1;
        }
        TreeNode* rootx=findandDelete(root);
        vector<TreeNode*> ans;
        
        if(rootx==root){
           if(root->right)  ans.push_back(root->right);
           if(root->left)  ans.push_back(root->left);
        }else{
             ans.push_back(root);
        }
    
        for(auto it: trees){
            if(it->left){
              ans.push_back(it->left);  
            }
            if(it->right){
               ans.push_back(it->right);
            }
        }
        
        return ans;
    }
};