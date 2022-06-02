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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> nodes;
        while(head){
            nodes.push_back(head->val);
            head=head->next;
        }

        stack<int> s;
        for (int i = nodes.size() - 1; i >= 0; i--) { 
           int val=nodes[i];
           while (!s.empty() && s.top() <= nodes[i]) { 
                s.pop(); 
            
           }
        
          nodes[i] = s.empty() ? 0 : s.top(); 
          s.push(val); 
       }
       return nodes;
        
    
        
    }
};