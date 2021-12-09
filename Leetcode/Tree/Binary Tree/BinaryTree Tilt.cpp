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
class Solution
{
public:
  int tiltSum = 0;
  int findTilt(TreeNode *root)
  {
    DFS(root);
    return tiltSum;
  }
  int DFS(TreeNode *root)
  {
    if (!root)
      return 0;
    int leftSum = DFS(root->left);
    int rightSum = DFS(root->right);
    tiltSum += abs(leftSum - rightSum);
    return leftSum + rightSum + root->val;
  }
};
Time Complexity : O(N), where N is the number of nodes in the given tree. We are traversing over each ndoe of the tree only once
Space Complexity : O(H), required for recursive stack. In case of skewed tree, this would be O(N), while in case of balanced tree, this would be O(logN)