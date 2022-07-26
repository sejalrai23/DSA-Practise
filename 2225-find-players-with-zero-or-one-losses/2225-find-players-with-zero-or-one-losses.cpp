class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> in;
        
        for(auto it : matches){
            if(!in[it[0]]){
                in[it[0]]=0;
            }
            
            in[it[1]]++;
        }
        vector<int> ans1 , ans2;
        for(auto it: in ){
            // cout<<it.first<<"-"<<it.second<<endl;
           if(it.second==0){
               ans1.push_back(it.first);
           }
            else if(it.second==1){
                ans2.push_back(it.first);
            }
            
           
        }
        return {ans1 , ans2};
    }
};