// { Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


 // } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    int length(struct Node* head){
        int cnt=0;
        while(head){
            cnt++;
            head=head->next;
        }
        return cnt;
    }
    struct Node* reverse(struct Node* head){
        if(head==NULL || head->next==NULL) return head;
        
        struct Node* newHead=reverse(head->next);
        head->next->next=head;
        head->next=NULL;
        return newHead;
        
    }
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
         Node* temp1=first;
        temp1=reverse(temp1);
         Node* temp2=second;
        temp2=reverse(temp2);
        // cout<<temp1->data<<"-"<<temp2->data<<endl;
        int m1=length(temp1);
        int m2=length(temp2);
        Node* res1=temp1;
         Node* res2=temp2;
        if(m2>m1){
            
            while(res1->next) res1=res1->next;
            for(int i=m1;i<m2;i++){
                res1->next=new  Node(0);
                res1=res1->next;
            }
        }else if(m2<m1){
            
            while(res2->next) res2=res2->next;
            for(int i=m2;i<m1;i++){
                res2->next=new  Node(0);
                res2=res2->next;
            }
        }
        int carry=0, sum;
        Node* ans=new  Node(-1);
        Node* anstemp=ans;
        while(temp1 && temp2){
            // cout<<temp1->data<<"-"<<temp2->data<<"-"<<carry<<endl;
            sum= temp1->data+ temp2->data+ carry;
             carry=sum/10;
            sum=sum%10;
           
            // cout<<sum<<"-"<<carry<<endl;
            anstemp->next=new  Node(sum);
            // cout<<anstemp->data<<endl;
            anstemp=anstemp->next;
            temp1=temp1->next;
            temp2=temp2->next;
            
        }
        if(carry>0) anstemp->next=new  Node(carry);
  
        return reverse(ans->next);
        
        
        
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
  // } Driver Code Ends