/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void setParents(unordered_map<TreeNode* , TreeNode*> & mp, TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode* node= q.front();
            q.pop();
            if(node->left){
                mp[node->left]=node;
                q.push(node->left);
            }
            
            if(node->right){
                mp[node->right]=node;
                q.push(node->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode* , TreeNode*> par;
        setParents(par , root);
        
        unordered_map<TreeNode* , bool> vis;
        
        queue<TreeNode*> q;
        q.push(target);
        vis[target]=true;
        int lev=0;
        while(!q.empty()){
            int s= q.size();
            if(lev==k) break;
            lev++;
            for(int i=0;i<s;i++){
                TreeNode* node= q.front();
                q.pop();
                
                if(node->left && !vis[node->left]){
                    q.push(node->left);
                    vis[node->left]=true;
                    
                } 
                if(node->right && !vis[node->right]) {
                   q.push(node->right);
                    vis[node->right]=true;
                }
                
                if(par[node] && !vis[par[node]]) {
                     q.push(par[node]);
                    vis[par[node]]=true;
                }
                  
            }
        }
        
        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        
        return ans;
    }
};