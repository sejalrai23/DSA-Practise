class Solution {
public:
    int getArea(vector<int>& heights){
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
                // cout<<heights[i]<<"-"<<i <<"-"<<st.top()<<endl;
                maxi=max(maxi , h*w);
            }
            st.push(i);
        }
        return maxi;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row = matrix.size() , col=matrix[0].size();
        vector<vector<int>> dp(row , vector<int>(col , 0));
        int maxi=0;
        for(int i=0;i< row ;i++){
            for(int j=0;j<col ;j++){
                if(i==0){
                    dp[i][j]= matrix[i][j]-'0';
                
                }else{
                    if(matrix[i][j]!='0'){
                    dp[i][j]= dp[i-1][j] + matrix[i][j]-'0';
                    }
                }
            }
            maxi=max(maxi , getArea(dp[i]));
           
        }
        
        // for(int i=0;i<row;i++){
        //     for(int j=0;j<col ;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return maxi;
    }
};