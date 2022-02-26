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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* dummy=new ListNode(0);
        ListNode* head1=dummy;
        while(head && head->next){
            if(head->val==0){
                head=head->next;
                int sum=0;
                while(head->val!=0){
                    sum+=head->val;
                    head=head->next;
                }
                dummy->next=new ListNode(sum);
                dummy=dummy->next;
            }
           
        }
        return head1->next;
        
    }
};