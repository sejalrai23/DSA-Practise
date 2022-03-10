class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> stck;
        string ans="";
        for(int i=0;i<s.length();i++){
            if(stck.empty()){
                stck.push(s[i]);
                ans+=s[i];
            }else{
                 if(s[i]==stck.top()){
                     stck.pop();
                     ans.pop_back();
                 }else{
                     stck.push(s[i]);
                     ans+=s[i];
                 }
            }
           
        }
        
        
        return ans;
        
    }
};