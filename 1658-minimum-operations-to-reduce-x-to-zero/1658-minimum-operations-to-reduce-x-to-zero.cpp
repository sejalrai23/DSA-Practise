class Solution {
public:

    int minOperations(vector<int>& nums, int x) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        sum=sum-x;
        if(sum<0) return -1;
        int i=0,j=0, req=0, flag=0, maxi=0;
        while(j<nums.size()){
            req+=nums[j];
            // if(req<sum){
            //     j++;
            // }
            while(req>sum){
               req-=nums[i];
                i++;
            }
            if(req==sum){
                maxi=max(maxi,j-i+1);
                flag=1;
            }
            j++;
            
        }
        // cout<<sum<<"-"<<maxi<< "-"<<flag<<endl;
        if(flag){
            return nums.size()-maxi;
        }
        return -1;
        
    }
};