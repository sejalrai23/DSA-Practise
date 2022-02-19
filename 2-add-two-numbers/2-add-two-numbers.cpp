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
//     ListNode* add(ListNode* l1 , ListNode* l2, int c){
//         ListNode* ans = new ListNode();
//        if (l1 == NULL and l2 == NULL) {
//             if(c>0)return new ListNode(c);
//             return NULL;
          
         
//        }
// 	   else if (l1 == NULL) return ans->next=add(new ListNode(0), l2, c);
// 	   else if (l2 == NULL)  return ans->next=add(l1, new ListNode(0), c); 
        
        
//         if(c+l1->val+l2->val > 9){
//             ans->val= (c+l1->val+l2->val)%10;
//             c= (c+l1->val+l2->val)/10;
//         }else {
//             ans->val=c+l1->val+l2->val;
//         }
//         cout<<l1->val << "-"<< l2->val << "-"<<c<<"-"<<ans->val<<endl;
//         ans->next = add(l1->next,l2->next,c);
//         return ans;
         
       
        
//     }
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//        return add(l1,l2,0);
       
        
        
//     }
// };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, int carry = 0)
    {
        if(!l1 and !l2)
        {
            if(carry > 0)
            {
                return new ListNode(carry);
            }
            return nullptr;
        }
        int op1 = l1 ? l1->val : 0;
        int op2 = l2 ? l2->val : 0;
        int sum = op1 + op2 + carry;
        ListNode* res = new ListNode(sum%10);
        res->next = addTwoNumbers(l1 ? l1->next : nullptr,l2 ? l2->next : nullptr,sum/10);
        return res;
    }
};