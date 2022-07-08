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
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL || head->next==NULL ) return NULL;
        int len=0;
        ListNode* a=head;
        while(a){
            len++;
            a=a->next;
        }
        int mid= len/2;
        // cout<<mid<<endl;
        a=head;
        while(mid!=1){
           if(a->next) a=a->next;
            else{
                break;
            }
           mid--;
        }
        if(a->next) a->next=a->next->next;
        return head;
    }
};