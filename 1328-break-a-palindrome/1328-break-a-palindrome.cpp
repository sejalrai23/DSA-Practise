class Solution {
public:
    string breakPalindrome(string s) {
        // int i=0 , j=palindrome.length()-1;
        if(s.length()==1) return "";
        bool res=false;
        int first=0 , last=0;
        if(s.length()%2==0){
            first=s.length()/2-1;
            last=s.length()/2;
        }else if(s.length()%2!=0){
            first=s.length()/2-1;
            last=s.length()/2+1;
        }
        
        for(int i=0;i<=first;i++){
            if(s[i]!='a'){
                s[i]='a';
                res=true;
                break;
            }
        }
        if(res) return s;
        else if(!res){
            s[s.length()-1]='b';
            return s;
        }
        return "";
    }
};