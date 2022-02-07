class Solution {
public:
    void permute(string& s , int idx, string ans,vector<string>& v){
    if(idx==s.length()){
        v.push_back(ans);
        ans="";
        return;
    }
     if(isalpha(s[idx])){
          s[idx]=tolower(s[idx]);
    ans+=s[idx];
    permute(s,idx+1,ans,v);
    ans.pop_back();
    s[idx]=toupper(s[idx]);
    ans+=s[idx];
    permute(s,idx+1,ans,v);
         
     }else{
         ans+=s[idx];
         permute(s,idx+1,ans,v);
     }
   
    
    
}
    vector<string> letterCasePermutation(string s) {
        string ans="";
        vector<string> v;
    permute(s,0,ans,v);
        return v;
        
    }
};