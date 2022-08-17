class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), start = 0, end = 0;
        while (end < n - 1) {
			int maxend=0;
			for (int i = start; i <= end; i++) {
                if (i + nums[i] >= n - 1) return true;
				maxend = max(maxend, i + nums[i]);
			}
            if(maxend==0) return false;
            start = end + 1;
            end = maxend;
        }
		return true;
    }
};