class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int> vis(rooms.size()+1,0);
        int cnt=0;
        for(int i=0;i<rooms.size();i++){
            if(!vis[i]){
                cnt++;
                queue<int> q;
                q.push(i);
                vis[i]=1;
                while(!q.empty()){
                    int node=q.front();
                    q.pop();
                    for(auto it:rooms[node]){
                        if(!vis[it]){
                            q.push(it);
                            vis[it]=1;
                        }
                    }
                }
            }
        }
        return cnt==1;
        
    }
};