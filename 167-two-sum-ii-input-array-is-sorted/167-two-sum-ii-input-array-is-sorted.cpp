class Solution {
public:
    int BinarySearch(vector<int>& nums, int st , int end, int val){
        while(st<=end){
            int mid= st+ (end-st)/2;
            if(nums[mid]==val){
                return mid;
            }else if(nums[mid]<val){
                st=mid+1;
            }else{
                end=mid-1;
            }
        }
        return -1;
        
        
    }
    vector<int> twoSum(vector<int>& nums, int target) {
        int ans=-1;
        int n=nums.size()-1;
        for(int i=0;i<nums.size();i++){
            int val=target-nums[i];
            ans=BinarySearch(nums , i+1,n, val);
            if(ans!=-1){
                return {i+1, ans+1};
            }
            
        }
        return {};
        
        
    }
};