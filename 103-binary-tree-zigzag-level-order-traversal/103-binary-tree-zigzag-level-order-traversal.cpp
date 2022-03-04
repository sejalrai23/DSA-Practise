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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==NULL){
            return res;
        }
        queue<TreeNode*> nodes;
        nodes.push(root);
        bool l2r= true;
        while(!nodes.empty()){
            int s=nodes.size();
            vector<int> row(s);
            for(int i=0;i<s;i++){
                TreeNode* node=nodes.front();
                nodes.pop();
                int idx= l2r ? i : s-1-i;
                row[idx]=node->val;
                if(node->left){
                    nodes.push(node->left);
                }
                if(node->right){
                    nodes.push(node->right);
                }
            }
            l2r=!l2r;
            res.push_back(row);
        }
        return res;
        
    }
};