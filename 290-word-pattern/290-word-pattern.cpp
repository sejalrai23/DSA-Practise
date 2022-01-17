class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<char,string> m;
        istringstream iss(s);
        int i=0;
        set<char> p1;
        set<string> s2;
        while(iss && i<pattern.length()){
            string fin;
            iss>>fin;
            m.insert({pattern[i],fin});
            p1.insert(pattern[i]);
            s2.insert(fin);
            i++;   
        }
        if((p1.size()!=s2.size()) ){
            return false;
        }
        string ans="";
        for(int i=0;i<pattern.length();i++){
            auto it=m.find(pattern[i]);
            if(it!=m.end()){
                ans+=it->second;
                i!=pattern.length()-1 ? ans+=" ": ans;
            }   
        }
        return ans==s;    
    }
};

// TC= 0(Nlogn) + 0(Nlogn)
// SC= 0(3N)