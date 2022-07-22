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
    ListNode* partition(ListNode* head, int x) {

        ListNode* res=new ListNode(0);
        ListNode* res2=new ListNode(0);
        res2->next=head;
        res->next=head;
        ListNode* head2=res2;
        ListNode* head1=res;

        while(res && res->next && res2 && res2->next){
            if(res->next->val<x) res=res->next;
            else{
               res->next=res->next->next; 
            }
            if(res2->next->val>=x) res2=res2->next;
            else{
                res2->next=res2->next->next;
            }
        }
        

        res->next=head2->next;
        return head1->next;
        
    }
};