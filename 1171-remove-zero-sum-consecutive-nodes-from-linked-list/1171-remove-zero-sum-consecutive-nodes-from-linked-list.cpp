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
  void deleteList(ListNode* head) {
        ListNode *nextptr= nullptr;
        while(head) {
            nextptr = head->next;

            head = nextptr;
        }
    }
    

    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int , ListNode*> ump;
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ump[0]=dummy;
        int sum=0;
        ListNode *curr = head;
          ListNode *start = nullptr, *end = nullptr, 
                *after_start = nullptr, *after_end = nullptr;
        while(curr) {
            sum += curr->val;
            ump[sum] = curr;
            curr = curr->next;
        }
        sum=0;
        curr=dummy;
         while(curr) {
            sum += curr->val;
            ListNode *last_seen_pos = ump[sum];
            after_start = curr->next;
            after_end = last_seen_pos->next;
            if(last_seen_pos != curr) {
                last_seen_pos->next = nullptr;
                deleteList(after_start);
            }
            
            curr->next = after_end;
            curr = curr->next;
        }
        return dummy->next;
        
        
    }
};