class Solution {
public:
    string minRemoveToMakeValid(string s) {
       stack<int> stck;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                stck.push(i);
            }
            else if(s[i]==')'){
                if(!stck.empty()){
                    stck.pop();
                }else{
                    s[i]='#';
                }
            }
        }
        while(!stck.empty()){
            s[stck.top()]='#';
            stck.pop();
        }
        s.erase(remove(s.begin(), s.end(), '#'), s.end());
        return s;
    }
};