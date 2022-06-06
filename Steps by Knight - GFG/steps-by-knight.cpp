// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	    queue<pair<int,int>> q;
	    q.push({KnightPos[0], KnightPos[1]});
	    vector<vector<int>> dist(N+1, vector<int>(N+1,0));
	    vector<int> x={-1,-1, 1 ,1 ,2 ,2 , -2 , -2};
	    vector<int> y={2, -2, -2, 2, -1, 1, 1, -1};
	    while(!q.empty()){
	        int s=q.size();
	        for(int i=0;i<s;i++){
	            auto nodes=q.front();
	            q.pop();
	            if(nodes.first==TargetPos[0] && nodes.second==TargetPos[1]){
	                return dist[nodes.first][nodes.second];
	            }
	            for(int k=0;k<8 ; k ++){
	                int x1=nodes.first+x[k];
	                int y1=nodes.second+y[k];
	                if(x1>0 && x1<=N && y1>0 && y1<=N && dist[x1][y1]==0){
	                    dist[x1][y1]=dist[nodes.first][nodes.second]+1;
	                    q.push({x1,y1});
	                }
	            }
	        }
	    }
	    return dist[TargetPos[0]][TargetPos[1]];
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends