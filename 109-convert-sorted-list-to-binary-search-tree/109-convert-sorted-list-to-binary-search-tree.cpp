/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* buildTree(vector<int>& vec, int st , int end){
        if(st>end) return NULL;
        int mid= st + (end-st)/2;
        TreeNode* root= new TreeNode(vec[mid]);
        root->left=buildTree(vec, st , mid-1);
        root->right=buildTree(vec, mid+1 , end);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> vec;
        ListNode* itr= head;
        while(itr){
            vec.push_back(itr->val);
            itr=itr->next;
        }
        return buildTree(vec , 0 , vec.size()-1);
        
    }
};