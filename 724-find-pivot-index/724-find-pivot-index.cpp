class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        vector<int> f(n,0);
        vector<int> b(n , 0);
        f[0]=nums[0];
        b[n-1]=nums.back();
        for(int i=1;i<nums.size();i++){
            f[i]=f[i-1]+nums[i];
            b[n-i-1]= b[n-i] + nums[n-i-1];
        }
        
        for(int i=0;i<n;i++){
            
            if(f[i]==b[i]) return i;
        }
        
        return -1;
    }
};