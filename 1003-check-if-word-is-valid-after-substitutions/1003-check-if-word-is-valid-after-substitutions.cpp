class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for(int i=0;i<s.length();i++){
            if(s[i]=='a') st.push(s[i]);
            
            else if(s[i]=='b'){
                if(st.empty() || st.top()!='a') return false;
                st.push(s[i]);
            }
            
            else if(s[i]=='c'){
                if(st.empty() || st.top()!='b') return false;
                st.pop();
                if(st.empty() || st.top()!='a') return false;
                st.pop();
            }
            
            
        }
        
        return st.empty();
    }
};