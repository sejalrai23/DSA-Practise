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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans;
        ListNode* dum=head;
        int len=0;
        while(dum){
           dum=dum->next;
           len++;
        }
        //case-1 when len can be equally divided in k parts
        if(len%k==0 && len!=0){
            int q=len/k;
            while(head){
                ListNode* itr=head;
                ListNode* rev=itr;
                for(int i=0;i<q-1;i++){
                   itr=itr->next;
                    
                }
                head=itr->next;
                itr->next=NULL;
                ans.push_back(rev);   
            }
        }
        //case 2 when len < k
        else if (len%k==len){
            int rem=k-len;
            while(head){
                ListNode* itr=head;
                head=itr->next;
                itr->next=NULL;
                ans.push_back(itr);
            }
            for(int i=0;i<rem;i++){
                ans.push_back({});
            }
        }
        //case 3 when len%k!=0
        else{
             int ex =len%k;
             int ac=len/k;
             int ac2=ac+1;
            for(int i=0;i<ex;i++){
                ListNode* itr=head;
                ListNode* rev=itr;
                for(int j=0;j<ac2-1;j++){
                    itr=itr->next;
                }
                head=itr->next;
                itr->next=NULL;
                ans.push_back(rev);    
                
            }
            while(head ){
             
                ListNode* itr2=head;
                ListNode* rev2=itr2;
                for(int i=0;i<ac-1;i++){
                    itr2=itr2->next;
                }
                head=itr2->next;
                itr2->next=NULL;
                ans.push_back(rev2);
            }
        }
        return ans;    
    }
};