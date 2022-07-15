// { Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int helpaterp(vector<vector<int>> hospital)
    {
        //code here
        int n=hospital.size();
        int m= hospital[0].size();
        int cnt=0;
        queue<pair<int, int>> q;
        for(int i=0;i<n ;i++){
            for(int j=0;j<m ;j++){
                if(hospital[i][j]==1) cnt++;
                else if(hospital[i][j]==2) q.push({i,j});
            }
        }
        int time=0;
        vector<int> x={0, 0, -1 , 1};
        vector<int> y={1 , -1, 0, 0};
        // cout<<cnt<<endl;
        while(!q.empty()){
            int s=q.size();
            
            for(int i=0;i<s;i++){
                int x1= q.front().first;
                int y1=q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    int nx1= x1+x[i];
                    int ny1=y1+y[i];
                    if(nx1 >=0 && nx1<n && ny1>=0 && ny1<m && hospital[nx1][ny1]==1){
                        // cout<<nx1<<"-"<<ny1<<endl;
                        hospital[nx1][ny1]=2;
                        q.push({nx1, ny1});
                        cnt--;
                    }
                }
            }
            time++;
        }
        //  cout<<cnt<<endl;
        return cnt==0 ? time-1 : -1;
        
        
        
    }
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R;int C;
        
        cin>>R>>C;
        vector<vector<int>> hospital;
        int i,j;
        for(i=0;i<R;i++)
         {   vector<int> temp;
             for(j=0;j<C;j++)
            {
                int k;
                cin>>k;
                temp.push_back(k);
            }
            hospital.push_back(temp);
         }
        
        Solution ob;
        int ans = ob.helpaterp(hospital);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends