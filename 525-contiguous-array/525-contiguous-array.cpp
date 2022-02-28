class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int ans=0;
        map<int,int> m;
        m[0]=-1;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i]==0 ? -1 :1;
            if(m.find(sum)!=m.end()){
                int len=i-m[sum];
                if(ans<len){
                    ans=len;
                }
            }else{
                m[sum]=i;
            }
            
        }
        return ans;
    }
};