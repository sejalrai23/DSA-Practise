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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k==0){
            return head;
        }
        int len=0;
        ListNode* dummy=head;
        ListNode* start=head;
        while(dummy){
            len++;
            dummy=dummy->next;
        }
        int piv = len-k%len;
        // cout<<piv<<endl;
        if(piv==0|| piv==len){
            return head;
        }
        
        while(piv-1){
           start=start->next;
            piv--;
        }
        ListNode* rot=start->next;
        ListNode* end= rot;
        start->next=NULL;
        while(end->next){
            end=end->next;
        }
        end->next=head ;
        head=rot;
        return head;
        
    }
};