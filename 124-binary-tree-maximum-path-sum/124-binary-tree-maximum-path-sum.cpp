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
    int sum(TreeNode* root ){
        if(root==NULL) return 0;
        
       
        
        
        int ls= max(0 , sum(root->left));
        int rs= max(0,sum(root->right));
        
        maxi=max(maxi , ls+rs+root->val);
        // cout<<maxi<<endl;
        
        return root->val+ max(ls , rs);
    }
    int maxPathSum(TreeNode* root) {
      int ans= sum(root);
        // cout<<ans<<endl;
      return maxi;
    }
};