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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
        if(depth==1){
            TreeNode* ans= new TreeNode(val);
            ans->left=root;
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        int lev=0;
        
        while(!q.empty()){
            int s=q.size();
            lev++;
            for(int i=0;i<s;i++){
                
                TreeNode* node=q.front();
                // cout<<node->val<<endl;
                q.pop();
                if(lev==depth-1){
                    TreeNode* addleft= new TreeNode(val);
                    TreeNode* addright= new TreeNode(val);
                    TreeNode* left =NULL ;
                    TreeNode* right=NULL;
                    if(node->left){
                        left= node->left;
                    }
                    if(node->right){
                        right= node->right;
                    }
                    node->left= addleft;
                    addleft->left= left;
                    node->right= addright;
                    addright->right= right;
                  
                            
                }else if(lev>=depth){
                    break;
                }
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                
            }
        }
        return root;
    }
};