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
     vector<int> largestValues(TreeNode* root) {
         vector<int> ans;
         if(root==NULL){
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int s=q.size();
            int maxi=INT_MIN;
            
            for(int i=0 ; i <s;i++){
                TreeNode* node =q.front();
                q.pop();
                if(node->left!=NULL){q.push(node->left);}
                if(node->right!=NULL){q.push(node->right);}
                maxi=max(maxi,node->val);
            }
            ans.push_back(maxi);
        }
        return ans;
        
    }
};