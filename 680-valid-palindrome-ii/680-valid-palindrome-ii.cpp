class Solution {
public:
    bool isValid(string s, int st , int end){
        while(st<=end){
            if(s[st]==s[end]){
                st++;
                end--;
            }else{
                return false;
            }
        }
        return true;
    }
    bool validPalindrome(string s) {
        int l=0, h=s.length()-1;
        int cnt=0,flag=0;
        while(l<h){
            if(s[l]!=s[h]){
                return isValid(s,l+1,h) || isValid(s,l,h-1);
            }
            l++;
            h--;
        }

        return  true;
        
    }
};