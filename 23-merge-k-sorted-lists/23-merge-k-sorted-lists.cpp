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
   
    struct comp{
        bool operator()(ListNode* a,ListNode* b){
            return a->val > b->val;
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return NULL;
        
        priority_queue< ListNode*, vector<ListNode*> , comp> pq;
        
        
        for (int i = 0; i < lists.size(); i++){
            if(lists[i]) pq.push(lists[i]);
        }
        
        ListNode* ans=new ListNode(-1);
        ListNode* dum=ans;
        // cout<<pq.size()<<endl;
        while(!pq.empty()){
            ListNode* top= pq.top();
            pq.pop();
            dum->next=top;
            dum=dum->next;
            if(top->next) pq.push(top->next);
        }
            
        
        return ans->next;
    }
};
