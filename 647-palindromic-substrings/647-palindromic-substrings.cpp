class Solution {

public:
    int countSubstrings(string s) {
        int st=0,cnt=s.length();
        int maxLen=1;
        for(int i=1;i<s.length();i++){
            // #even
            int l=i-1;
            int r=i;
            while(l>=0 && r<s.length() && s[l]==s[r]){

                l--;
                r++;
                cnt++;
            }
            int l1= i-1;
            int r1 =i+1;
            while(l1>=0 && r1<s.length() && s[l1]==s[r1]){
     
                l1--;
                r1++;
             cnt++;
            }           
        }
        // cout<<s
        return cnt;
    }
};
    