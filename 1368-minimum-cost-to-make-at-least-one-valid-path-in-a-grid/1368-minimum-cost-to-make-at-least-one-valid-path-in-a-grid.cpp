class Solution {
public:
    int dx[5] = {-1,0,0,1,-1};
    int dy[5] = {-1,1,-1,0,0};
    
    struct Node{
        int x, y, dir;
        Node(int x, int y, int dir){
            this->x = x;
            this->y = y;
            this->dir = dir;
        }
    };
    
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, INT_MAX));
        queue<Node*> q;
        q.push(new Node(0,0,grid[0][0]));
        vis[0][0] = 0;
        
        while(!q.empty()){
            auto cur = q.front(); q.pop();
            int x = cur->x;
            int y = cur->y;
            int dir = cur->dir;
            for(int i=1; i<=4; ++i){
                int x1 = x+dx[i], y1 = y+dy[i];
                if(x1<0 || x1>=n || y1<0 || y1>=m) continue;
                int newCost = dir == i ? vis[x][y] : vis[x][y]+1;
                int newDir = grid[x1][y1];
                if(vis[x1][y1] > newCost){
                    // cout<<x<<"-"<<y<<"-"<<x1<<"-"<<y1<<"-"<<newCost<<endl;
                    vis[x1][y1] = newCost;
                    q.push(new Node(x1,y1,newDir));
                }
            }
        }
        return vis[n-1][m-1];
    }
};