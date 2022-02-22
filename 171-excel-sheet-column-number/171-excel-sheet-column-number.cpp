class Solution {
public:
    int titleToNumber(string col) {
        long long res=0;
        for(long long i=0;i<col.length();i++){
            res=res*26 + col[i]-'A' +1;
        }
        return res;
        
    }
};  