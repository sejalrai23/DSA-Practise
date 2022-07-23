class Solution {
public:
    int minimumDeletions(string s) {
        stack<char> st;
        int cnt=0;
        for(int i=0;i<s.length();i++){
         if(!st.empty() && st.top()=='b' && s[i]=='a'){
             st.pop();
             cnt++;
         }else{
             st.push(s[i]);
         }
        }
        return cnt;
    }
};