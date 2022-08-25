class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> mp;
        
        for(auto it: ransomNote){
            mp[it]++;
        }
        
        for(auto it: magazine){
            if(mp.find(it)!=mp.end()){
                 mp[it]--; 
            }
          
            if(mp[it]==0) mp.erase(it);
        }
        // cout<<mp.size()<<endl;
        return mp.size()==0;
    }
};