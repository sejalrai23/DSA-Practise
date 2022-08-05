class Solution {
public:
    int recur(int n,int k){
        if(n==1 || k==1) return 0;
        if(k==(pow(2,n)/2) || k==(pow(2,n)-1)) return 1;
        else if(k<(pow(2,n)/2)) return recur(n-1,k);
        else if(k>(pow(2,n)/2)) return !recur(n-1,(int)(pow(2,n)-k));
        return 0;
    }
    
    char findKthBit(int n, int k) {
        int ch = recur(n,k);
        // cout<<ch<<endl;
        return ch==1 ? '1' :'0';
    }
};