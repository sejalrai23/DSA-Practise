class Solution {
public:
    int minSwaps(string s) {
        int n=s.length();
        int o=0, c=0;
        int cnt=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='[') o++;
            if(s[i]==']') c++;
            
            if(c>o) {
                while(s[n-1]!='['){
                    n--;
                }
                cnt++;
                o++;
                c--;
            } 
        }
        return cnt;
    }
};