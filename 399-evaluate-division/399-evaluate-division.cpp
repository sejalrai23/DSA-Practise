class Solution {
public:
    double dfs(map<string,vector<pair<string,double>>>& mp , vector<string> &v , string q1, string& q2){
         if(mp.find(q1)==mp.end() || mp.find(q2)==mp.end()) {
             return -1.0;
         }
         
         if(q1==q2) {
             return 1.0;
         }
        v.push_back(q1);
        for(auto it : mp[q1]){
            auto fin=find(v.begin(),v.end(),it.first);
            if(fin==v.end()){
                
                double res=dfs(mp,v,it.first,q2);
                 if(res!=-1.0){
                     return res*it.second;
                 }
            }
           
        }
        return -1.0;
        
    }
    vector<double> calcEquation(vector<vector<string>>& eq, vector<double>& val, vector<vector<string>>& q) {
        map<string, vector<pair<string, double>>> mp;
        vector<double> res;
        for(int i=0;i<eq.size();i++){
            mp[eq[i][0]].push_back(make_pair(eq[i][1],val[i]));
            mp[eq[i][1]].push_back(make_pair(eq[i][0], 1/val[i]));
        }
        for(auto it :q){ 
           vector<string> v;
            double ans=dfs(mp,v,it[0],it[1]);
            res.push_back(ans);
            
        }

        return res;
            
    }
};