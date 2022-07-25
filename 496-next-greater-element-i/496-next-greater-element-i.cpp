class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        int n=nums2.size();
        vector<int> vec(n);
        map<int, int> mp;
        for(int i=n-1;i>=0;i--){
            mp[nums2[i]]= i;
            while(!st.empty() && nums2[st.top()]<= nums2[i]) st.pop();
            
            if(st.empty()) vec[i]=-1; 
             
            else vec[i]=nums2[st.top()];
            
            st.push(i);
        }
        vector<int> ans(nums1.size());
        
        for(int i=0;i<nums1.size();i++){
            ans[i]= vec[mp[nums1[i]]];
        }
        return ans;
    }
};