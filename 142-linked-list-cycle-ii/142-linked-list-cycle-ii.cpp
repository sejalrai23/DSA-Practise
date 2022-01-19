/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
         if(head==NULL || head->next==NULL){
            return NULL;
        }
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast->next && fast->next->next){
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow){
                slow=head;
                while(slow!=fast){
                    slow=slow->next;
                    fast=fast->next;
                }
                return slow;
            }
        }
        return NULL;
        
    }
        
    
};

// TC=O(N)
//SC=O(N)

// To understand this solution, you just need to ask yourself this question.
// Assume the distance from head to the start of the loop is x1
// the distance from the start of the loop to the point fast and slow meet is x2
// the distance from the point fast and slow meet to the start of the loop is x3

// What is the distance fast moved? What is the distance slow moved? And their relationship?

// x1 + x2 + x3 + x2
// x1 + x2
// x1 + x2 + x3 + x2 = 2 (x1 + x2)
// Q: Why x1 + x2 + x3 + x2 = 2 (x1 + x2)?

// Ans: Its just the relationship between the distance travelled by fast ptr and the distance travelled by the slow ptr.
// As fast ptr, runs twice the speed of slow ptr. Therefore, when they meet, distance travelled by fast ptr will be 2*(distance travelled by slow ptr).

// Therefore, x1 = x3.

// Hope this makes sense.
