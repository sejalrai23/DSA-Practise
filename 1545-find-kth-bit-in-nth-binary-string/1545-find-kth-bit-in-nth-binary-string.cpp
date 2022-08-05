class Solution {
public:
    string inverse(string s){
        for(int i=0;i<s.length();i++){
            if(s[i]=='0') s[i]='1';
            else s[i]='0';
        }
        reverse(s.begin(), s.end());  
        return s;
    }
    
    string buildString(int i, string s , int n){
        if(i==n) return s;
        string ans= s+ '1' + inverse(s); 
        return buildString(i+1 , ans , n);
    }
    
    char findKthBit(int n, int k) {
        string ans= buildString(1, "0", n);
        // cout<<ans.length()<<endl;
        return ans[k-1];
    }
};