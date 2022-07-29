class Solution {
public:
    vector<int> getPattern(string s){
        if(s.length()==0) return {};
        
        vector<int> v;
        unordered_map<char , int> ump;
        int x=1;
        for(int i=0;i<s.length();i++){
            if(ump.find(s[i])==ump.end()){
                ump[s[i]]=x;
                x++;       
            }
            v.push_back(ump[s[i]]);
        }
        return v;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        if(pattern.length()==0) return {};
        
        vector<int> pat= getPattern(pattern);
        vector<string> ans;
        for(auto it: words){
            vector<int> word= getPattern(it);
            if(pat==word){
                ans.push_back(it);
            }
        }
        return ans;
    }
};