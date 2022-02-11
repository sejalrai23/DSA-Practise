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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* dum= head;
        ListNode* start=head;
       
        int len=0;
        while(dum){
            dum=dum->next;
            len++;
            if(len==k-1){
                start=dum;
            }
            
        }
        int diff = len-2*k +1;
        cout<<start->val<<"-"<<len<<"-"<<diff;
        if(diff>0){
            ListNode* end=start;
             while(diff--){
                 end=end->next;
             }
             swap(start->val,end->val);
            
        }
        else if (diff<0){
            ListNode* end=head;
             int x= len-k;
             while(x--){
                end=end->next;
            }
            swap(end->val,start->val);
            
        }
        
        return head;
    }
};