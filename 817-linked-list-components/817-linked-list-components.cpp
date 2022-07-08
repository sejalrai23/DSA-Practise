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
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        if(head==NULL || nums.size()==0) return 0;
        int cnt=0, flag=0;
        unordered_map<int , int> mp;
        for(auto it : nums) mp[it]++;
        ListNode* p=head;
        while(p){
            if(mp[p->val]){
                flag=1;
            }else if(!mp[p->val]&& flag==1){
                cnt++;
                flag=0;
            }
            p=p->next;
        }
        if(flag) cnt++;
        return cnt;
        
    }
};