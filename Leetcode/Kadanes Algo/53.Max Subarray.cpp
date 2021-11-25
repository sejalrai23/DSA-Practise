class Solution
{
public:
  int maxSubArray(vector<int> &nums)
  {
    int sum = 0;
    int max_ = INT_MIN;
    for (auto i : nums)
    {
      sum += i;
      max_ = max(sum, max_);
      if (sum < 0)
      {
        sum = 0;
      }
    }
    return max_;
  }
};

//Time Complexity : O(n)
//space: o(1)