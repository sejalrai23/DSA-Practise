/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root==NULL) return {};
        queue<Node*> q;
        q.push(root);
        vector<vector<int>> ans;
        while(!q.empty()){
            vector<int> res;
            int n= q.size();
            for(int i=0;i<n;i++){
                Node* curr= q.front();
                q.pop();
                    res.push_back(curr->val);
                    for(auto x: curr->children){
                       q.push(x);
                    }
                }
            ans.push_back(res);
        }
        return ans;
    }
};