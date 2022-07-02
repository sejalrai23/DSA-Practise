// { Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution{
    public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    Node* lcs(Node* root , int a , int b){
        if(!root) return NULL;
        if(root->data==a || root->data==b) return root;
        Node* lh=lcs(root->left , a , b);
        Node* rh= lcs(root->right , a, b);
        if(lh!=NULL && rh!=NULL) return root;
        else if(lh!=NULL) return lh;
        else return rh;
        
    }
    int find(Node *root, int x) 
{ 
    // Base case 
    if (root == NULL) 
      return -1; 
  
    // Initialize distance 
    int dist = -1; 
  
    // Check if x is present at root or in left 
    // subtree or right subtree. 
    if ((root->data == x) || 
        (dist = find(root->left, x)) >= 0 || 
        (dist = find(root->right, x)) >= 0) 
        return dist + 1; 
  
    return dist; 
} 
    int findDist(Node* root, int a, int b) {
        // Your code here
            Node* ans= lcs(root, a, b);
            // cout<<ans->data<<endl;
            int a1= find(ans , a);
            int b1=find(ans, b);
            return a1+b1;
            
    }
};

// { Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        int n1, n2;
        scanf("%d %d ", &n1, &n2);
        Solution ob;
        cout << ob.findDist(root, n1, n2) << endl;
     
    }
    return 0;
}
  // } Driver Code Ends