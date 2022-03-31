class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int sum=0, maxi=0;
        for(int i=0; i<nums.size(); i++)
        {
            sum+=nums[i];
            maxi=max(maxi, nums[i]);
        }
        int low=maxi, high=sum;
        while(low<=high)
        {
            int s=0, d=1;
            int mid=low+(high-low)/2;
            for(int i=0; i<nums.size(); i++)
            {
                s+=nums[i];
                if(s>mid)
                {
                    d++;
                    s=nums[i];
                }
            }
            if(d<=m)
                high=mid-1;
            else
                low=mid+1;
        }
        return low;
    }
};