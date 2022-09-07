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
    int getHeight(TreeNode* root){
        if(root==NULL) return 0;
        int lh=getHeight(root->left);
        int rh= getHeight(root->right);
        return 1 + max(lh ,rh);
    }
    vector<vector<string>> printTree(TreeNode* root) {
        int h= getHeight(root)-1;
        vector<vector<string>> vec(h+1 , vector<string>(pow(2,h+1)-1 , ""));
        int n=pow(2,h+1)-1;
        queue<pair<TreeNode*,pair<int, int>>> q;
        q.push({root , {0 , (n-1)/2 }});
        
        while(!q.empty()){
            int s=q.size();
            for(int i=0;i<s;i++){
                TreeNode* node= q.front().first;
                int x= q.front().second.first;
                int y= q.front().second.second;
                q.pop();
                vec[x][y]=to_string(node->val);
                // cout<<x<<"-"<<y<<endl;
                if(node->left){
                    q.push({node->left , {x+1, y- pow(2, h-x-1)}});
                }
                if(node->right){
                     q.push({node->right , {x+1,  y+pow(2, h-x-1)}});
                }
            }
        }
        return vec;
    }
};