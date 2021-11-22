class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l=0, h=nums.size()-1;
        int c;
        while(l<=h){
            c=0;
            int mid=l+(h-l)/2;
            if(nums[mid]==target){
                return mid;
            }
            if(nums[mid]<target){
                l=mid+1;
            }else{
                h=mid-1;
            }
            c=mid;
            if(target>nums[c]){
                c=c+1;
            }
            
        }
        return c;
    }
    
};

// Given a sorted array of distinct integers and a target value, return the index if the target is found.If not, return the index where it would be if it were inserted in order.

//     You must write an algorithm with
//     O(log n) runtime complexity.