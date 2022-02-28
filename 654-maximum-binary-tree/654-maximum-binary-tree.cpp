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
    TreeNode* construct(int start , int end , vector<int>& nums){
        if(start>end){
            return NULL;
        }
        int mx_indx = max_element(nums.begin() + start, nums.begin() + end + 1) - nums.begin();
        TreeNode* root=new TreeNode(nums[mx_indx]);
        root->left=construct(start, mx_indx-1, nums);
        root->right= construct(mx_indx+1,end,nums);
        return root;
        
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
       
        return construct(0,nums.size()-1,nums);
    }
};