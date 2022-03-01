class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        ans[0]=0;
        int k=1;
        for(int i=1;i<=n;i++){
            if(2*k==i){
                k*=2;
            }
            ans[i]=ans[i-k]+1;
        }
        return ans;
    }
};