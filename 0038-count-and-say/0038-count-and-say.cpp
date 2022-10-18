class Solution {
public:
    string ans(string res){
        string req="";
        for(int i=0;i<res.length(); i ++){
            char c= res[i];
            int cnt=1;
            while( c== res[i+1]){
                i++;
                cnt++;
            }
            req+= to_string(cnt)+c;          
        }
        return req;
    }
    string countAndSay(int n) {
        string ini="1";
        string curr="";
        if(n==1) return ini;
        for(int i=2;i<=n ; i++){
            curr=ans(ini);
            ini=curr;
        }
        return curr;
        
    }
};