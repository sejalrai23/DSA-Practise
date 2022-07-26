class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n=heights.size();
        vector<int> ans(n);
        
        stack<int> st;
        
        for(int i=n-1;i>=0 ;i--){
            while(!st.empty() && heights[st.top()]<= heights[i]) {
                ans[i]++;
                st.pop();
            }
            
            if(!st.empty()) ans[i]++; //because this ith person can see the one which is greater than this 
             
            st.push(i);
        }
        
        return ans;
    }
};