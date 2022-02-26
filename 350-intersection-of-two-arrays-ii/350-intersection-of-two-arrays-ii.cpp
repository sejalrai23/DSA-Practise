class Solution {
public:
    bool BinarySearch(vector<int>& nums ,int target){
        int s=0,e=nums.size()-1;
        while(s<=e){
            int mid= s+(e-s)/2;
            if(target==nums[mid]){
                auto it = nums.begin()+mid;
                nums.erase(it);
                return true;
            }
            else if(target<nums[mid]){
                e=mid-1;
            }else{
                s=mid+1;
            }
        }
        return false;
    }
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        if(nums1.size()>nums2.size()){
            sort(nums1.begin(),nums1.end());
            for(int i=0;i<nums2.size();i++){
                if(BinarySearch(nums1,nums2[i])==true){
                    ans.push_back(nums2[i]);
                }
            }
        }
        else if(nums1.size()<=nums2.size()){
            sort(nums2.begin(),nums2.end());
            for(int i=0;i<nums1.size();i++){
                if(BinarySearch(nums2,nums1[i])==true){
                    ans.push_back(nums1[i]);
                }
            }
        }
        return ans;
    }
};