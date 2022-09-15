class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if(changed.size()%2!=0) return {};
        sort(changed.begin(), changed.end());
        map<int, int> mp;
        int n=changed.size();
        
        for(auto it: changed){
            mp[it]++;
        }
        vector<int> ans;
        for(auto it: changed){
            if(mp.find(it)!=mp.end()){
                int val= 2*it;
                mp[it]--;
                if(mp[it]==0) mp.erase(it);
                if(mp.find(val)!=mp.end()){
                    ans.push_back(it);
                    mp[val]--;
                    if(mp[val]==0) mp.erase(val);
                }else if(mp.find(val)==mp.end()){
                    mp[it]++;
                }
            }
        }
        

        if(ans.size()<n/2) return {};
        return ans;
        
        
        
    }
};


        

