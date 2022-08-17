class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       int sum= INT_MIN;
      int  maxi=0;
        for(int i=0 ; i <nums.size();i++){
            maxi+=nums[i];
            if(sum<maxi ){
                sum=maxi;
            }
            // cout<<maxi<<"-"<<sum<<endl;
            if(maxi<0){
                maxi=0;
            }
        }
        
        // Your code here
        return sum;
    }
};