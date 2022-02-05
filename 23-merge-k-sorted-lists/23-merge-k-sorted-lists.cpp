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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
        if(l1==NULL || l2==NULL){
            return l1==NULL ? l2 : l1;
        }
        ListNode* v1=new ListNode();
        if(l1->val <= l2->val){
            v1->val = l1->val;
            v1->next= mergeTwoLists(l1->next , l2);
        }
         else{
            v1->val=l2->val;
            v1->next= mergeTwoLists(l1 , l2->next);
        }
        return v1;
        
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0){
            return NULL;
        }
        // ListNode* ans=lists[0] ;
        // for(int i =1 ; i<lists.size() ; i++){
        //     ans = mergeTwoLists(ans, lists[i]);
        // }
        while(lists.size() > 1){
        lists.push_back(mergeTwoLists(lists[0], lists[1]));
        lists.erase(lists.begin());
        lists.erase(lists.begin());
        }
    
        return lists[0];
    }
};