class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> s1;
        for(auto x :s){
            if(!s1.empty() && x=='#'){
                s1.pop();
            }else if(x!='#'){
                s1.push(x);
            }
        }
        string ans="";
        while(!s1.empty()){
            ans+=s1.top();
            s1.pop();
        }
        for(auto x :t){
            if(!s1.empty() && x=='#'){
                s1.pop();
            }else if(x!='#'){
                s1.push(x);
            }
        }
        string ans1="";
        while(!s1.empty()){
            ans1+=s1.top();
            s1.pop();
        }
        // cout<<ans<<"-"<<ans1<<endl;
        if(ans==ans1){
            return true;
        }
        return false;
        
    }
};