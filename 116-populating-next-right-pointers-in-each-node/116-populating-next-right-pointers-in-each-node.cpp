/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL){
            return NULL;
        }
        vector<vector<TreeNode*>> ans;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int s=q.size();
            vector<Node*> level;
            for(int i=0;i<s;i++){
                Node* node =q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right)q.push(node->right);
                level.push_back(node);
            }
            for(int i=0;i<level.size();i++){
                if(i!=level.size()-1){
                    level[i]->next=level[i+1];
                }else{
                    level[i]->next=NULL;
                }
                
            }
        }
        return root;
        
    }
};