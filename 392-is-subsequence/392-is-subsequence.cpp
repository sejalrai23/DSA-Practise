class Solution {
public:
    bool isSubsequence(string s, string t) {
        int j=0,cnt=0;
        for(int i=0;i<t.length() && j<s.length();i++){
            if(s[j]==t[i]){
                cnt++;
                j++;
            }else{
                continue;
            }
            
        }
        return cnt==s.length();
    }
};