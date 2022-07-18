class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxi=0;
        int n=heights.size();
        for(int i=0;i<=n ;i++){
            while(!st.empty() && (i==n || heights[st.top()] >= heights[i])){
                int h=heights[st.top()];
                int w;
                st.pop();
                if(st.empty()) w=i;
                else w= i- st.top()-1;
                maxi=max(maxi , h*w);
            }
            st.push(i);
        }
        return maxi;
    }
};