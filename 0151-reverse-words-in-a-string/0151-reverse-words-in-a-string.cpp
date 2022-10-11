class Solution {
public:
    string reverseWords(string s) {
        string res="";
        stringstream ss(s);
        string word;
        while(ss>>word){
            res=word+" "+res;
        }
        res.pop_back();
        return res;
        
    }
};