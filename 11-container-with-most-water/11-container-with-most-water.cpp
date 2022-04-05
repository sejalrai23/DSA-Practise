class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1, area = 0, temp;
        while(i < j)
        {
            temp = (height[i]<height[j]) ? height[i]*(j-i) :  height[j]*(j-i);
            if(temp > area)
                area = temp;
            if(height[i]<=height[j])
                i++;
            else
                j--;
        }
        return area;
    }
};