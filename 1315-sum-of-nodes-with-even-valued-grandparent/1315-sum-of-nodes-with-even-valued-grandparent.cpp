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
    int findHeight(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int lh=findHeight(root->left);
        int rh=findHeight(root->right);
        return 1+max(lh,rh);
    }
    void sumNodes(TreeNode* root,int &sum , int lev,int height){
        if(root==NULL){
            return;
        }
            if(root->val%2==0){
                if(lev+2<height){
                    if(root->left){
                        if(root->left->left) sum+=root->left->left->val;
                        if(root->left->right) sum+=root->left->right->val;
                    }
                    if(root->right){
                       if(root->right->left) sum+=root->right->left->val; 
                       if(root->right->right) sum+=root->right->right->val;
                    }
                }
            }
            
        
        sumNodes(root->left,sum,lev+1,height);
        sumNodes(root->right,sum,lev+1,height);
        
    }
    int sumEvenGrandparent(TreeNode* root) {
        int sum=0;
        int height=findHeight(root);
        int lev=0;
        sumNodes(root,sum,lev,height);
        return sum;
        
    }
};