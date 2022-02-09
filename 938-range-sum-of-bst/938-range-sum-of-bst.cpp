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
// class Solution {
// public:
//     void sumBST(TreeNode* root , int low , int high , int& sum){
//         if(root==NULL){
//             return ;
//         }
//         sumBST(root->left,low,high,sum);
//         if(root->val >=low && root->val <=high ){
//             sum+=root->val;
//         }
//         sumBST(root->right,low , high,sum);
        
//     }
//     int rangeSumBST(TreeNode* root, int low, int high) {
//         int sum=0;
//         sumBST(root, low , high , sum);
//         return sum;
        
//     }
// };
class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int H) {
        if(!root) return 0;
        int ans = root -> val >= L && root -> val <= H ? root -> val : 0;
        if(root -> val > L) ans += rangeSumBST(root -> left, L, H);
        if(root -> val < H) ans += rangeSumBST(root -> right, L, H);
        return ans;
    }
};