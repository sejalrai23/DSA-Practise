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
     vector<vector<int>> verticalTraversal(TreeNode* root) {
	    map<int, vector<int> > m;  
	    queue<pair<int, TreeNode*> > q; 
	    q.push(make_pair(0, root));  
	    while(!q.empty()) {
		   multiset<pair<int,int>> tmp; 
		    int len=q.size();
		    for(int i=0;i<len;++i) {
			     auto p=q.front();q.pop();
			     tmp.insert(make_pair(p.first, p.second->val));
			     if (p.second->left) q.push(make_pair(p.first-1, p.second->left));
			     if (p.second->right) q.push(make_pair(p.first+1, p.second->right));
		    }

		    for(auto p : tmp) m[p.first].push_back(p.second);
	   }

	   vector<vector<int> > res;
	   for(auto x : m) res.push_back(x.second);
	   return res;
  }
};