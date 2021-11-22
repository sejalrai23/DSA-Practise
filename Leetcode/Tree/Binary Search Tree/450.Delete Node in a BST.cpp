//Algorithm:
//search the node first and then check the right and left child if either of them is null then attach the not null one to parent root above it
// if left and right child exist then attach the right child to the last right child of left part and attach the left part to parent node and same viceversa can be done.

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
  TreeNode *deleteNode(TreeNode *root, int key)
  {
    if (root == NULL)
    {
      return NULL;
    }
    if (root->val == key)
    {
      return helper(root);
    }
    TreeNode *curr = root;
    while (root != NULL)
    {
      if (root->val > key)
      {
        if (root->left != NULL && root->left->val == key)
        {
          root->left = helper(root->left);
          break;
        }
        else
        {
          root = root->left;
        }
      }
      else
      {
        if (root->right != NULL && root->right->val == key)
        {
          root->right = helper(root->right);
          break;
        }
        else
        {
          root = root->right;
        }
      }
    }
    return curr;
  }

  TreeNode *helper(TreeNode *root)
  {
    if (root->left == NULL)
    {
      return root->right;
    }
    else if (root->right == NULL)
    {
      return root->left;
    }
    TreeNode *rightChild = root->right;
    TreeNode *lastRight = findLastRight(root->left);
    lastRight->right = rightChild;
    return root->left;
  }

  TreeNode *findLastRight(TreeNode *root)
  {
    if (root->right == NULL)
    {
      return root;
    }
    return findLastRight(root->right);
  }
};

//Time Complexity : O(Height of tree) and space Complexity is None