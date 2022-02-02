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
       
        if( head==NULL){
            return head;
        }
         ListNode* dum=head;
        int val= dum->val;
        while(dum && dum->next){
            if(dum->next->val == val){
                dum->next= dum->next->next;
                
            }else{
                val=dum->next->val;
                dum=dum->next;
            }
        }
        return head;
    }
};