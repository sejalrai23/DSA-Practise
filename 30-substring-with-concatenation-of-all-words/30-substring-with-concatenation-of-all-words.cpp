class Solution {
public:
    bool checkSubstr(unordered_map<string , int> mp , int wordLen , int start , int windowLen , string s){
        
        // cout<<start<<"-"<<start+windowLen<<endl;
        for(int i=start;i<start+windowLen ; i+=wordLen){
            // cout<<i<<"-"<<wordLen<<endl;
            string sub= s.substr(i , wordLen);
            // cout<<sub<<endl;
            if(mp.find(sub)==mp.end()) return false;
            else{
                mp[sub]--;
               
                if(mp[sub]==0) mp.erase(sub);
            }
        }
        if(mp.size()==0) return true;
        return false;
    }
    
    vector<int> findSubstring(string s, vector<string>& words) {
       unordered_map<string , int> mp;
        
        for(auto it: words){
            mp[it]++;
        }
        int wordLen= words[0].size();
        int windowLen= words[0].size() * words.size();
        
        int i=0;
        vector<int> res;
        while(i+windowLen <=s.length()){
            // cout<<i<<endl;
            if(checkSubstr(mp , wordLen , i , windowLen, s)){
                res.push_back(i);
            
            }
            i++;
        }
        return res;
        
    }
};