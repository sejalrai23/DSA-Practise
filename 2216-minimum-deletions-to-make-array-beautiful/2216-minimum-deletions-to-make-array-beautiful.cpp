class Solution
{
    public:
        int minDeletion(vector<int> &nums)
        {
            int shift = 0;
            for (int i = 0; i < nums.size() - 1; i++)
            {
                if ((i + shift) % 2 == 0)
                {
                    if (nums[i] == nums[i + 1])
                    {
                        shift++;
                    }
                }
            }
            if ((nums.size() - shift) % 2 == 1)
            {
                shift++;
            }
            return shift;
        }
};