class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& w, vector<vector<int>>& friends, int id, int level) {
        int nodes=friends.size();
        vector<int> vis(nodes,0);
        // for(auto it:friends[22]){
        //     cout<<it<<",";
        // }
        //  for(auto it : w[22]){
        //     cout<<it<<",";
        // }
        int lev=0;
        map<string,int> m;
        queue<int> q;
        q.push(id);
        while(!q.empty()){
            lev++;
            int s=q.size();
            for(int i=0;i<s;i++){
                int n=q.front();
                q.pop();
                vis[n]=1;
            
               for(auto it: friends[n]){
                // cout<<it<<endl;
                   if(!vis[it]){
                if(lev==level){
                    for(auto x:w[it]){  
                        m[x]++;    
                    } 
                
                }
                q.push(it); 
                }
                
                vis[it]=1;
            }
                
            }
            
        }
            
        multimap<int, string> MM;
        vector<string> ans;
        for (auto& it : m) {
            MM.insert({ it.second, it.first });
        }

        for (auto& it : MM) {
          ans.push_back(it.second);
         }
        cout<<ans.size()<<endl;
        return ans;
        
    }
};