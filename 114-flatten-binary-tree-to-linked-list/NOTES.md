recursive - reverse pre order traversal
iterative also same using stack
morris traversal approach
​
APPROACH -> O ( N ) SPACE
By using brute force, we can traverse the tree in preorder manner and store the result in a vector.
Later using that vector , we can arrange nodes, such as
​
vector[i] -> right = vector[i+1];
vector[i] -> left = NULL;
​
https://leetcode.com/problems/flatten-binary-tree-to-linked-list/discuss/2338767/C%2B%2B-3-solutions-Recursion-Stack-Morris-Traversal-Clean-code-Full-Explained
​
​
​