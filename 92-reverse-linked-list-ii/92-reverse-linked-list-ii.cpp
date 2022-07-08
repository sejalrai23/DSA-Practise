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

    ListNode* reverseBetween(ListNode* head, int m, int n) {
       if(m==n) return head; 
        ListNode* a=head;
        ListNode* prevx=NULL;
        ListNode* finHead=NULL;
        int cnt=0;
        while(a){
            cnt++;
            if(cnt==m){
                int cntx=0;
                finHead=a;
                ListNode* curr=a;
                ListNode* prev=NULL;
                ListNode* temp=a;
                while(curr!=NULL && cntx<=(n-m)){
                     temp=curr->next;
                    curr->next=prev;
                    prev=curr;
                    curr=temp;
                    cntx++;
                }
                finHead->next=curr;
                if(prevx) prevx->next=prev;
                else return prev;
                
                
            }else{
                prevx=a;
                a=a->next;
            }
            
        }
        
        return head;
        
    }
};