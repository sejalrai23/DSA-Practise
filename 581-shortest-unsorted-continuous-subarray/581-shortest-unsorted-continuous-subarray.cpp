class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> res=nums;
        sort(res.begin(),res.end());
        int i=0, j=nums.size()-1;
        while(i<nums.size() && nums[i]==res[i]){
            i++;
        }
        while(j>i && nums[j]==res[j]){
            j--;
        }
        return j-i+1;
        
        
    }
};