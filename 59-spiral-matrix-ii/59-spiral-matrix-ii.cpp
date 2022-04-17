class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > ans(n, vector<int>(n));
    
        int left=0, right=n-1, top=0, bottom=n-1;
        int cnt = 1;
    
        while(left <= right && top <= bottom)
        {
            for(int i = left; i<= right; i++)
                ans[top][i] = cnt++;
            top++;
        
            for(int i = top; i<= bottom; i++)
                ans[i][right] = cnt++;
            right--;
        
            for(int i = right; i>= left; i--)
                ans[bottom][i] = cnt++;
            bottom--;
        
            for(int i = bottom; i>= top; i--)
                ans[i][left] = cnt++;
            left++;
        }
    
        return ans;
    }
};