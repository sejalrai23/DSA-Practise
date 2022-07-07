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
        while(head){
            cnt++;
            head=head->next;
        }
        return cnt;
    }
    
      ListNode* reverse(ListNode* head){
        if(head==NULL || head->next==NULL) return head;
        
        ListNode* newHead=reverse(head->next);
        head->next->next=head;
        head->next=NULL;
        return newHead;
        
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1=reverse(l1); 
        ListNode* temp2=reverse(l2);
        
        // cout<<temp1->data<<"-"<<temp2->data<<endl;
        int m1=length(temp1);
        int m2=length(temp2);
        ListNode* res1=temp1;
        ListNode* res2=temp2;
        if(m2>m1){
            
            while(res1->next) res1=res1->next;
            for(int i=m1;i<m2;i++){
                res1->next=new  ListNode(0);
                res1=res1->next;
            }
        }else if(m2<m1){
            
            while(res2->next) res2=res2->next;
            for(int i=m2;i<m1;i++){
                res2->next=new  ListNode(0);
                res2=res2->next;
            }
        }
        int carry=0, sum;
        ListNode* ans=new  ListNode(-1);
        ListNode* anstemp=ans;
        
        while(temp1 && temp2){
            sum= temp1->val+ temp2->val+ carry;
            carry=sum/10;
            sum=sum%10;
            anstemp->next=new  ListNode(sum);
            anstemp=anstemp->next;
            temp1=temp1->next;
            temp2=temp2->next;
            
        }
        if(carry>0) anstemp->next=new  ListNode(carry);
  
        return reverse(ans->next);
    }
};


  
   