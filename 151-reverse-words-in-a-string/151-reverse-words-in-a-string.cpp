class Solution {
public:
    string reverseWords(string s) {
        string res="";
        stringstream ss(s);
        string word;
        while(ss>>word){
            reverse(word.begin(),word.end());
            res+=word;
            res+=" ";
        }
        res.pop_back();
        reverse(res.begin(),res.end());
        return res;
        
    }
};