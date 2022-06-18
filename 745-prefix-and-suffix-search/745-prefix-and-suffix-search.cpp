struct Node{
    Node* links[28]; // extra |
    int idx;
    
    bool ContainsKey(char ch){
        return links[ch-'a']!=NULL;
    }
    
    Node* getNode(char ch){
        return links[ch-'a'];
    }
    
    void put(char ch , Node* node){
        links[ch-'a']= node;     
    }
    
    void setEnd(int& ind){
        idx=ind;
    }
    int getIdx(){
        return idx;
    }
    
};

class Trie{
private : Node* root;
public :
    Trie(){
        root=new Node();
    }
    
    void insert(string &word , int &ind){
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->ContainsKey(word[i])){
                node->put(word[i], new Node());
            }
            node=node->getNode(word[i]);
            node->setEnd(ind);
            
        }
    }
    
    int startsWith(string &word){
        Node* node=root;
        for(int i=0;i<word.length();i++){
            if(node->ContainsKey(word[i])){
                node=node->getNode(word[i]);
            }else{
                return -1 ;  //asked to return -1 if no word exists
            }
        }
        return node->getIdx();
    }
       
};

class WordFilter {
private : Trie *obj = new Trie();
public:
    WordFilter(vector<string>& words) {
        int n=words.size();
        for(int i=0;i<n ;i++){
            string curr= words[i];
            int s= curr.length();
            for(int j=0;j<=s ; j++){
                string res= curr.substr(j) + '|' + curr;
                obj->insert(res , i);
            }
        }
        
    }
    
    int f(string prefix, string suffix) {
        string ans= suffix + '|' + prefix;
        return obj->startsWith(ans);
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */