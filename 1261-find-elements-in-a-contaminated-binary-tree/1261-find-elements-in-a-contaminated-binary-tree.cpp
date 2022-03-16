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
class FindElements {
public:
    void recoverTree(TreeNode* root){
        if(root==NULL){
            return;
        }
        if(root->left){
            root->left->val=2*root->val +1;
        }
        if(root->right){
            root->right->val=2*root->val+2;
        }
        recoverTree(root->left);
        recoverTree(root->right);
    }
    TreeNode* ans;
    FindElements(TreeNode* root) {
        ans=root;
        ans->val=0;
        recoverTree(ans);
        
    }
    bool FindVal(TreeNode* root,int target){
        if(root==NULL){
            return false;
        }
        if(root->val==target){
            return true;
        }
        return FindVal(root->left,target) || FindVal(root->right,target);
    }
    
    bool find(int target) {
        return FindVal(ans,target);
        
        
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */