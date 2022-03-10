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
        ListNode*  c=new ListNode(0,head);
        ListNode* d=c;
        int cnt=0;
        while( head && head->next){
           
            if(head->next!=NULL && head->val==head->next->val){
                int val=head->val;
                while(head->next!=NULL && head->val==head->next->val){
                    head=head->next;
                }
                d->next=head->next;
                head=head->next;
                // d=d->next;

                
            }else{
                d->next=head;
                head=head->next;
                d=d->next;
            }
            // head=head->next;
            
            
        }
        return c->next;
        
    }
};


