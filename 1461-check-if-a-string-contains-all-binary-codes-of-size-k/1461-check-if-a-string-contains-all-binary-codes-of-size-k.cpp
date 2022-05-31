class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(k>s.size()){
            return false;
        }
        unordered_set<string> ins;
        for(int i=0;i<=s.size()-k;i++){
            // cout<<s.substr(i,k)<<endl;
            ins.insert(s.substr(i,k));
        }
        // cout<<ins.size()<<endl;
        return ins.size()==pow(2,k);
        
    }
};