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
   ListNode* removeNthFromEnd(ListNode* head, int n) {
	ListNode* iter = head;
	int len = 0, i = 1;
	while(iter) iter = iter -> next, len++;    // finding the length of linked list
	if(len == n) return head -> next;
       int pos = len-n ;
       // cout<<pos<<endl;
       iter=head;
       while(i<pos){
          iter=iter->next; 
           i++;
       }
       // cout<<iter->val<<endl;
       iter->next=iter->next->next;
       return head;
       
       
   }
};

// TC = O(LEN OF LINKED LIST)