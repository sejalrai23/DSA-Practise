class Solution {
public:
    vector<string> res;
    void recur(int n, int m , string s){
        if(n==0 && m==0) {
            res.push_back(s);
            return;
        }
        if(n>0) recur(n-1,m , s+'(');
        if(m>n) recur(n, m-1, s+')'); //because we cannot only add ')' without '( '
    }
    vector<string> generateParenthesis(int n) {
        recur(n, n, "");
        return res;
    }
};