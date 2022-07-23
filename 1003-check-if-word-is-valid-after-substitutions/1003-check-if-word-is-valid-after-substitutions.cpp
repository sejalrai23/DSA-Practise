class Solution {
public:
    bool isValid(string s) {
        string f="abc";
        bool k= true;
        while(k && s.length()>0){
            auto pos= s.find(f);
            if (pos != string::npos){
                s.erase(pos, f.length());
            }else{
                k=false;
            }
        }
        
        if(k==false) return false;
        return true;
    }
};