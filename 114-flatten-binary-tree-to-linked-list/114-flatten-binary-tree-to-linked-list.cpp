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

// TC= O(N) , SC=O(N)
// class Solution {
// public:
//     TreeNode* prev= NULL;
//     void flatten(TreeNode* root) {
//         if(root==NULL){
//             return;
//         }
//         flatten(root->right);
//         flatten(root->left);
//         root->right=prev;
//         root->left=NULL;
//         prev=root;
       
        
//     }
// };

//iterative  TC=O(N), SC=O(N)

// class Solution {
// public:
//     void flatten(TreeNode* root){
//         if(root==NULL){
//             return;
//         }
//         stack<TreeNode*> s;
//         s.push(root);
//         while(!s.empty()){
//             TreeNode* cur=s.top();
//             s.pop();
//             if(cur->right) s.push(cur->right);
//             if(cur->left) s.push(cur->left);
//             if(!s.empty()){
//                 cur->right=s.top();
//             }
//             cur->left=NULL;
//         }
//     }
    
// };


//MORRIS TRAVERSAL TC=0(N) , SC= O(1)
class Solution {
public:
    void flatten(TreeNode* root){
        TreeNode* curr=root;
        while(curr){
            if(curr->left!=NULL){
               TreeNode* prev=curr->left;
                
                while(prev->right){
                    prev=prev->right;
                }
                
                prev->right=curr->right;
                curr->right=curr->left;
                curr->left=NULL;
     
            }
            curr=curr->right;
            // if(curr) cout<<curr->val<<endl;
        }
    }
};
