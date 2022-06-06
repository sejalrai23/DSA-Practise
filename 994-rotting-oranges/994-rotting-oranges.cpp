class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        queue<pair<int, int>> q;
        int cnt=0, total=0;
        for(int i=0;i<n ;i++){
            for(int j=0;j<m ;j++){
                if(grid[i][j]!=0){
                    total++;
                }
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        vector<int> x={0, 0, -1 , 1};
        vector<int> y={1 , -1, 0, 0};
        int days=0;
        while(!q.empty()){
            int k=q.size();
            cnt+=k;
            while(k--){
                int x1= q.front().first;
                int y1=q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    int nx1= x1+x[i];
                    int ny1=y1+y[i];
                    if(nx1 >=0 && nx1<n && ny1>=0 && ny1<m && grid[nx1][ny1]==1){
                        // cout<<nx1<<"-"<<ny1<<endl;
                        grid[nx1][ny1]=2;
                        q.push({nx1, ny1});
                    }
                }
            }
            days++;
            
        }
        // cout<<"*"<<endl;
        // cout<<total <<"-"<<cnt<<endl;
        int ans=0;
        if(days==0){
            ans=0;
        }else{
            ans=days-1;
        }
        return total==cnt ? ans :-1;
        
        
    }
};