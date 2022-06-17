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
    // no-camera =0 
    // has-camera=2;
    // not-needed=1;
    int ans=0;
    int recur(TreeNode* &root ){
        if(root==NULL) return 1;
        int l= recur(root->left);
        int r= recur(root->right);
        if(l==0 || r==0) {
            ans++;
            return 2;
        }
        else if(l==1 && r==1) return 0;
        else if(l==2 || r==2) return 1;
        
        return -1;
        
      
    }
    int minCameraCover(TreeNode* root) {
       if(recur(root)==0) ans++;
        return ans;
    }
};