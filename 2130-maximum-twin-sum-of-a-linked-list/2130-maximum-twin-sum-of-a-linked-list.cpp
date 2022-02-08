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
    int pairSum(ListNode* head) {
        stack<int> s;
        ListNode* dum= head;
        int n=0;
        while(dum){
            s.push(dum->val);
            n++;
            dum=dum->next;
        }
        n=n/2;
        int maxi= INT_MIN;
        while(n!=0){
            maxi=max(maxi , head->val + s.top());
            s.pop();
            head=head->next;
            n--;
        }
        return maxi;
        
    }
};