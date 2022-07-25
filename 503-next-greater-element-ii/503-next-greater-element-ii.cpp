class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums2) {
        stack<int> st;
        int n=nums2.size();
        vector<int> ans(nums2.size());
         for(int i=n-1 ;i>=0; i--){
             st.push(i);
         }
         for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums2[st.top()]<= nums2[i]) st.pop();
            
            if(st.empty()) ans[i]=-1; 
             
            else ans[i]=nums2[st.top()];
            
            st.push(i);
        }
        return ans;
    }
};