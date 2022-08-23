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
    ListNode* makeList(ListNode* head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* dum=makeList(head->next);
        head->next->next=head;
        head->next=NULL;
        
        return dum;    
    }
    
    bool isPalindrome(ListNode* head) {
      
        ListNode* slow=head;
        ListNode* fast=head->next;
        
        while(fast!=NULL && fast->next!=NULL){
			slow=slow->next;
			fast=fast->next->next;
		}
        // cout<<slow->val<<endl;
        ListNode* next1=slow->next;
        
        slow->next=NULL;
        ListNode* first=makeList(head);
        // cout<<next1->val<<"-"<<slow->val<<endl;
        if(fast==NULL) slow=slow->next;
        
        while(slow && next1){
            // cout<<slow->val <<"-"<<next1->val<<endl;
            if(slow->val!=next1->val) return false;
            slow=slow->next;
            next1=next1->next;
        }
        return true;
        
    }
};