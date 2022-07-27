class Solution {
public:
    int cnt;
    void traverseTree(vector<int> &left, vector<int> &right, int root, vector<bool> &vis) {
        if(root==-1 || vis[root]==true){
            return;
        }
        vis[root]=true;
        cnt++;
        traverseTree(left,right,left[root],vis);
        traverseTree(left,right,right[root],vis);
        return;
    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> indegree(n,0);
        for (int i=0;i<n;i++) {
            if(leftChild[i]!=-1 && ++indegree[leftChild[i]]>1){ 
                return false;
            }
            if(rightChild[i]!=-1 && ++indegree[rightChild[i]]>1){
                return false;
            }
        }
        int root=-1;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                if(root!=-1){  
                    return false;
                }
                root=i;
            }
        }        
        if(root==-1){ 
            return false;
        }
        vector<bool> vis(n,false);
        cnt=0;
        traverseTree(leftChild,rightChild,root,vis);
        return cnt==n; 
    }
};