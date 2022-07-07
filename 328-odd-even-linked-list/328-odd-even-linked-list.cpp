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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* evenH = NULL;
        ListNode* oddH = NULL;
        ListNode* evenN = NULL;
        ListNode* oddN = NULL;
        
        ListNode* curr = head;
        int i=0;
        while (curr != NULL) {
            if (i % 2 == 0) {
                if (evenH == NULL)
                    evenH = evenN = curr;
                else {
                    evenN->next = curr;
                    evenN = evenN->next;
                }
            }
            else {
                if (oddH == NULL)
                    oddH = oddN = curr;
                else {
                    oddN->next = curr;
                    oddN = oddN->next;
                }
            }
            curr = curr->next;
            i++;
        }
    
        if (evenH && oddH) {
            head = evenH;
            evenN->next = oddH;
            oddN->next = NULL;
        }
        
        return head;
    }
};