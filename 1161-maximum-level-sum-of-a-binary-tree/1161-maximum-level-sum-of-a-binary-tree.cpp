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
    int maxLevelSum(TreeNode* root) {
        if(root==NULL) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int minlev=0, lev=0, maxSum=INT_MIN;
        while(!q.empty()){
            int n=q.size();
            int sum=0;
            lev++;
            for(int i=0;i<n;i++){
                
                TreeNode* node=q.front();
                q.pop();
                sum+= node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(sum>maxSum){
               maxSum= sum;
                minlev=lev;
            }
        }
        return minlev;
    }
};