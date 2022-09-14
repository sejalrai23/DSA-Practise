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
    int ans=0;
    void countPalindrome(TreeNode* root , unordered_map<int, int>& mp ){
        if(root==NULL) return;
        if(!root->left && !root->right){
            mp[root->val]++;
            int cnt=0;
            for(auto it: mp){
                // cout<<it.first<<"-"<<it.second<<endl;
                if(it.second%2!=0){
                    cnt++;
                }
            }
        
            mp[root->val]--;
            if(cnt<=1) ans++;
            // cout<<"*"<<endl;
            return;
        }
        mp[root->val]++;
        countPalindrome(root->left , mp);
        countPalindrome(root->right , mp);
        mp[root->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        unordered_map<int , int> mp;
        countPalindrome(root , mp);
        return ans;
    }
};