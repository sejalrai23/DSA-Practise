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
    ListNode* deleteDuplicates(ListNode* head) {
        map<int,int> m;
        ListNode* dum=head;
        while(dum){
            m[dum->val]++;
            dum=dum->next;
        }
        ListNode* ans=new ListNode(0);
        ListNode* ret=ans;
        for(auto it:m){
            if(it.second==1){
               ans->next=new ListNode(it.first); 
               ans=ans->next;
            }
            // ans=ans->next;
        }
        return ret->next;
        
    }
};