class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        for(int i=0;i<nums.size();i++){
            int k=nums[i];
            int j=i+1;
            int a=k;
            while(j<nums.size()){
               
                if(a+1==nums[j]){
                    a=nums[j];
                    j++;
                }
                else{
                    break;
                }
            }
            i=j-1;
            if(k==nums[j-1]){
                ans.push_back(to_string(k));
            }else{
                ans.push_back(to_string(k)+"->"+to_string( nums[j-1]));
                
            }
            
          
            
        }
        return ans;
        
    }
};