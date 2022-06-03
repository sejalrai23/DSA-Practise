class Solution {
public:
    string smallestSubsequence(string s) {
        map<char, int> mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }
        // cout<<('a'-'0')-49<<endl;
        vector<int> vis(26,0);
        stack<char> st;
        for(int i=0;i<s.length();i++){
            mp[s[i]]--;
            if(vis[s[i]-'a']){continue;}
            while(!st.empty() && s[i]-'0' < st.top()-'0' &&mp[st.top()]!=0){
                   vis[st.top()-'a']=0;
                   st.pop(); 
                  
            }
                 
                st.push(s[i]);
                vis[s[i]-'a']=1;
                      
        
                

        }
        string ans="";
        while(!st.empty()){
            ans=st.top()+ans;
            st.pop();
        }
        return ans;
    }
};
