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
    vector<vector<int>> v;
    void findDepth(TreeNode* root , int node, int c,int & count, TreeNode* par){
        if(root==NULL){
            return ;
        }
        if(root->val == node){
            // cout<<c<<endl;
            v.push_back({c,par->val});
            // count=c;
            return ;  
        }
        findDepth(root->left,node , c+1,count ,root);
        findDepth(root->right,node , c+1,count,root);  
        return ;

                

    }
    bool isCousins(TreeNode* root, int x, int y) {
        int x1=0,x2=0;
        findDepth(root,x,0,x1,root);
        findDepth(root,y,0,x2,root);

        // cout<<x1<<"-"<<x2<<endl;
        // for(auto it :v){
        //     cout<<it.first <<"-"<<it.second->val<<endl;
        // }
        if(v[0][0]!=v[1][0] || v[0][1]==v[1][1]){
            return false;
        }
        return true;
        
    }
};