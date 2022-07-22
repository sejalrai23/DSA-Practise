class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        
        for(int i=0;i<s.length();i++){
            if(s[i]=='(') st.push(i);
            else if(s[i]==')'){
                int idx=st.top();
                st.pop();
                reverse(s.begin()+idx+1 , s.begin()+i);
            }
        }
        string res="";
        for(auto it: s){
            if(it!='(' && it!=')'){
                res+=it;
            }
        }
        return res;
    }
};