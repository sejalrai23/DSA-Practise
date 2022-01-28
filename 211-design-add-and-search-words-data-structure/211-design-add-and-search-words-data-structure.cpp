class WordDictionary {
public:
    map<int,vector<string>> m;
    WordDictionary() {
         
    }
    
    void addWord(string word) {
       m[word.size()].push_back(word);
        
    }
    
    bool search(string word) {
        // if(m.size()==0){
        //     return false;
        // }
         
        for (auto& it : m[word.size()]){
            int i=0;
            while(i<word.size() && (word[i]==it[i] || word[i]=='.')){
                i++;
            }
            if(i==word.size()){
                return true;
            }
        }
        return false;
        
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */