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
    
    TreeNode* BuildTree(  vector<int>& nums , int strt , int end){
        if(strt>= end){
            return NULL;
        }
        int mid= (end-strt)/2 + strt;
        
        TreeNode* root=new TreeNode(nums[mid]);
        root->left=BuildTree(nums , strt , mid);
        root->right=BuildTree(nums , mid+1 , end);
        return root;
        
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return BuildTree(nums,0,nums.size());
        
    }
};