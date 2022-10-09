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
    
    bool findTarget(TreeNode* root, int k) {
        
        stack<TreeNode*> lst, rst;
		TreeNode *l = root, *r = root;
		while (l != nullptr) {
			lst.push(l);
			l = l->left;
		}
		l = lst.top();
		
		while (r != nullptr) {
			rst.push(r);
			r = r->right;
		}
		r = rst.top();

		while (l != r) {
		
			if (l->val + r->val == k) {
				return true;
			}
			
			if (l->val + r->val < k) {
				l = l->right;
				while (l != nullptr) {
					lst.push(l);
					l = l->left;
				}
				l = lst.top();
				lst.pop();
			} else {
				r = r->left;
				while (r != nullptr) {
					rst.push(r);
					r = r->right;
				}
				r = rst.top();
				rst.pop();
			}
		}
		return false;

    }
};