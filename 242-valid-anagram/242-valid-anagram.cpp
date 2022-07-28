class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<int, int> mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }
        
        for(int i=0;i<t.length();i++){
            mp[t[i]]--;
        }
        
        for(auto it: mp){
            if(it.second!=0) return false;
        }
        return true;
    }
};