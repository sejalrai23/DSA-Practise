class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> forw(n);
        forw[0]=1;
        vector<int> back(n);
        back[0]=1;
        
        for(int i=1;i<n;i++){
            forw[i]=forw[i-1]*nums[i-1];
            back[i]=back[i-1]*nums[n-i];
        }
        
        vector<int> res(n);
        for(int i=0;i<n;i++){
            // cout<<forw[i]<<"-"<<back[n-1-i]<<endl;
            res[i]=forw[i]*back[n-1-i];
        }
        return res;
    }
};