class Solution {
public:
    string removeOuterParentheses(string s) {
        string str="";
        int count=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                if(count){
                    str+="(";
                }
                count++;
            }else if(s[i]==')'){
                count--;
                if(count){
                    str+=")";
                }
            }
        }
        return str;
        
    }
};