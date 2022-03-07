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
// class Solution {
// public:
//     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//         if(list1 == NULL  || list2==NULL ){
//             return list1==NULL ? list2 : list1;
//         }
//         ListNode* v1=new ListNode();
//         if(list1->val ==list2->val || list1->val <list2->val){
//             v1->val=list1->val;
//             v1->next=mergeTwoLists(list1->next,list2);
         
//         }
//         else if(list1->val >list2->val){
//             v1->val= list2->val;
//             v1->next=mergeTwoLists(list1,list2->next);
            
//         }
//         // v1->next->next=mergeTwoLists(list1->next,list2->next);
//         return v1;
//     }
// };

class Solution{
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
          ListNode* v1=new ListNode(0);
        ListNode* ret=v1;
        while(l1!=NULL && l2!=NULL){
           
            if(l1->val<=l2->val){
                v1->next=new ListNode(l1->val);
                l1=l1->next;
            }
            else if(l2->val<l1->val){
                v1->next=new ListNode(l2->val);
                l2=l2->next;
            }
            v1=v1->next;   
        }
        if(l1==NULL){
            v1->next=l2;
        }else{
            v1->next=l1;
        }
        return ret->next;
    }
    
};