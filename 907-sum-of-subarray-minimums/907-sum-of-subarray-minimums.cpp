class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        //getting next smallest and previous smallest
        int mod=1e9+7;
        int n=arr.size();
        vector<int> left(n,0), right(n ,0);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();
            if(st.empty()) left[i]=i+1;
            
            else left[i]= i-st.top();
            st.push(i);
        }
        
        while(!st.empty()) st.pop();
        
        for(int i=n-1 ;i>=0 ;i--){
            while(!st.empty() && arr[st.top()]>arr[i]) st.pop();
            
            if(st.empty()) right[i]=n-i;
            else right[i]=st.top()-i;
            
            st.push(i);
        }
        long long ans=0;
        for(int i=0;i< n ;i++){
            cout<<left[i]<<"-"<<right[i]<<endl;
            long long prod= (left[i]*right[i])%mod;
            prod= (prod*arr[i])%mod;
            ans+=prod;
            ans=ans%mod;
        }
        return ans;
    }
};