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
    int length(ListNode* head){
        int cnt=0;
        while(head!=NULL){
            head=head->next;
            cnt++;
        }
        return cnt;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
         ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* nextHead;
        int cnt=0;
        while(curr!=NULL && cnt<k){
            nextHead=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextHead;
            cnt++;
        }
        
        if(nextHead!=NULL){
            if(length(nextHead)>=k){
                head->next=reverseKGroup(nextHead, k);
            }else{
                head->next=nextHead;
            }
        }
        return prev;
    }
};

