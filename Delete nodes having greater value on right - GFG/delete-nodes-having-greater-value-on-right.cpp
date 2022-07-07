// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



 // } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    public:
    Node* reverse(Node* head){
        if(head==NULL || head->next==NULL) return head;
        Node* newHead=reverse(head->next);
        head->next->next=head;
        head->next=NULL;
        return newHead;
    }
    Node *compute(Node *head)
    {
        // your code goes here
        Node* ans=reverse(head);
        Node* rev=ans;
        int mx=rev->data;
       
        while(rev && rev->next){
            if(rev->next->data < mx){
                rev->next=rev->next->next;
                
            }else{
                mx=rev->next->data;
                rev=rev->next;
            }
        }
        
        return reverse(ans);
        
    }
    
};
   


// { Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}
  // } Driver Code Ends