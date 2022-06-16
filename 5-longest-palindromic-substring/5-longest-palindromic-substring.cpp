class Solution {
public:
    string longestPalindrome(string s) {
        int st=0;
        int maxLen=1;
        for(int i=1;i<s.length();i++){
            // #even
            int l=i-1;
            int r=i;
            while(l>=0 && r<s.length() && s[l]==s[r]){
                if( r-l+1 > maxLen){
                    st=l;
                    maxLen=r-l+1;
                }
                l--;
                r++;
            }
            int l1= i-1;
            int r1 =i+1;
            while(l1>=0 && r1<s.length() && s[l1]==s[r1]){
                if(r1-l1+1>maxLen){
                    
                    st=l1;
                    maxLen=r1-l1+1;
                }
                l1--;
                r1++;
            }           
        }
        // cout<<
        return s.substr(st , maxLen);
    }
};