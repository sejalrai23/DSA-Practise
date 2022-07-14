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
    TreeNode* buildTree(vector<int>& pre ,int  prest ,int  prend , vector<int>& in , int inst , int inend, map<int,int>& mp){
        if(prest>prend || inst>inend) return NULL;
        TreeNode* root= new TreeNode(pre[prest]);
        int inRoot=mp[root->val];
        int numsLeft= inRoot-inst;
        root->left=buildTree(pre, prest+1 , prest+numsLeft , in , inst , inRoot-1 , mp);
        root->right=buildTree(pre, prest+numsLeft+1 , prend,in , inRoot+1 , inend , mp);
        return root;
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int , int> mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        return buildTree(preorder , 0 ,preorder.size()-1 ,inorder, 0 , inorder.size()-1 , mp);
    }
};