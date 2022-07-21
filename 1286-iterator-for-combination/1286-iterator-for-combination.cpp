class CombinationIterator {
public:
    vector<string> vec;
    int pos=0;
    void recur(int ind , int n , string & chars, string s){
        if( n==0){
            vec.push_back(s);
            return;
        }
        for(int i=ind ;i<chars.length();i++){
            s.push_back(chars[i]);
            recur(i+1 , n-1 , chars , s);
            s.pop_back();
        }     
        
    }
    CombinationIterator(string characters, int len) {
        string s="";
        recur(0 , len , characters , s);
        
    }
    
    string next() {
        return vec[pos++];
        
    }
    
    bool hasNext() {
        return pos<vec.size();
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */