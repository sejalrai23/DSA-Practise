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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* prev= head;
        ListNode* curr = head->next;
        ListNode* next = head->next->next;
        vector<int> v;
        int i=1;
        // int min_a = 1;
        // int max_a=1;
        while(prev && curr && next){
            if((prev->val> curr->val && curr->val < next->val) || (prev->val< curr->val && curr->val > next->val)){
                // min_a=min(min_a,i-min_a);
                // max_a=max(max_a, i-max_a);
                v.push_back(i);
                
            }
            i++;
            prev=prev->next;
            curr=curr->next;
            next=next->next;
        }
        int minx= INT_MAX;
        for(int i =1 ; i <v.size(); i++ ){
            minx=min(minx , v[i]-v[i-1]);
        }
        if(v.size()<=1){
            return {-1,-1};
        }
        // return { v[v.size()-1]- v[v.size()-2], v[v.size()-1]-v[0] };
        // cout<<minx<<"-"<<v[v.size()-1]-v[0];
        return {minx,v[v.size()-1]-v[0]};
        
        
    }
};