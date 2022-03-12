/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<int,Node*> m;
        map<Node*,int> m2;
        Node* ans= new Node(0);
        Node* ran=ans;
        Node* dum=ans;
        Node* head1=head;
        int len=0;
        int i=0;
        while(head1){
            ans->next=new Node(head1->val);
            m2[head1]=i;
            head1=head1->next;
            ans=ans->next;
           
            m[i]=ans;
            i++;
            len++;
        }
        ran=ran->next;
        while(head){
              if(head->random==NULL){
                ran->random=NULL;
            }else{
                 ran->random = m[m2[head->random]]; 
              }
            ran=ran->next;
            head=head->next;
          
        }
        return dum->next;
        
    }
};