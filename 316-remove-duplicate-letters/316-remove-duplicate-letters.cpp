class Solution {
public:
    string removeDuplicateLetters(string s) {
        string res="";
        vector<int> cnt(26,0);
        vector<int> vis(26,0);
        
        for(int i=0;i<s.length();i++){
            cnt[s[i]-'a']++;
        }
        for(int i=0;i<s.length();i++){
            cnt[s[i]-'a']--;
            if(!vis[s[i]-'a']){
                while(res.length()>0 && res.back()>s[i] && cnt[res.back()-'a']>0){
                vis[res.back()-'a']=0;
                 res.pop_back();
                }
                res+=s[i];
                vis[s[i]-'a']=1;
                
            }
            
        }
        return res;
        
    }
};