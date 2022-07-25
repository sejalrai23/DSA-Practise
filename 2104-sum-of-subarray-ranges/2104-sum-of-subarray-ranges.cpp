class Solution {
public:
    long long subArrayRanges(vector<int>& arr) {
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
        vector<int> left1(n,0), right1(n ,0);
        
         while(!st.empty()) st.pop();
        
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]<=arr[i]) st.pop();
            if(st.empty()) left1[i]=i+1;
            
            else left1[i]=i-st.top();
            st.push(i);
        }
        
         while(!st.empty()) st.pop();
        
         for(int i=n-1 ;i>=0 ;i--){
            while(!st.empty() && arr[st.top()]<arr[i]) st.pop();
            
            if(st.empty()) right1[i]=n-i;
            else right1[i]=st.top()-i;
            
            st.push(i);
        }
        
        long long ans=0;
        
        for(int i=0;i<n ;i++){
            // cout<<left1[i]<<"-"<<right1[i]<<endl;
            long long prod1= left[i]*right[i];
            long long prod2= left1[i]*right1[i];
           long long prod=(prod2 - prod1)*arr[i];
            ans+=prod;
        }
        
        return ans;
    }
};