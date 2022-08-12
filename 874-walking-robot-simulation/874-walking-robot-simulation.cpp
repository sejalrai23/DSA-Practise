class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        map<string, int> mp;
        for(auto it: obstacles){
            mp[to_string(it[0])+"#"+to_string(it[1])]++;
        }
        vector<vector<int>> vec={{0,1}, {1,0}, {0,-1}, {-1,0}}; // this cyclic ordering is important here 
        int dir=0;
        int x=0, y=0, maxi=0;
        
        // for(auto it: mp){
        //     cout<<it.first<<"-"<<it.second<<endl;
        // }
        for(int i=0;i<commands.size();i++){
            
            if(commands[i]==-1) dir++ ;
            
            if(commands[i]==-2) dir--;
            
            else {
                
                for(int k=0 ;k<commands[i];k++){
                    
                    if(mp.find(to_string(x+vec[dir][0])+"#"+to_string(y+vec[dir][1]))!=mp.end()){
                        break;
                    }else{
                        x+=vec[dir][0];
                        y+=vec[dir][1];
                        // cout<<x<<"-"<<y<<endl;
                        maxi=max(maxi ,x*x+y*y);
                    }
                    
                }
            }
            
            if(dir==-1) dir=3;
            if(dir==4) dir=0;
        }
        return maxi;
    }
};