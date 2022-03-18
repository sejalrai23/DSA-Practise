struct Node{
    Node* links[26];
    bool flag= false;
    
    bool containsKey(char ch){
        return (links[ch-'a']!=NULL);
    }
    Node* getChar(char ch){
        return links[ch-'a'];
    }
    void put(char ch,Node* node){
        links[ch-'a']=node;
    }
    void setEnd(){
        flag=true;
    }
    bool isEnd(){
        return flag;
    }    
};

class Trie{
private: Node* root;
public:
    Trie(){
        root=new Node();
    }
    void insert(string s){
        Node* node=root;
        for(auto c:s){
            if(!node->containsKey(c)){
                node->put(c,new Node());
            }
            node=node->getChar(c);
        }
        node->setEnd();
    }
    string search(string &s,string &ans){
        Node* node=root;
        for(auto c:s){
            if(!node->containsKey(c)){
                 break;
            }
                ans+=c;
                 node=node->getChar(c);
                if(node->isEnd()){
                    return ans;
                }
               
            
            
        }
        // ans+=s;
        return s;
        
    }
    
};
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie* trie=new Trie();
        for(auto i: dictionary){
            trie->insert(i);
        }
        stringstream ss(sentence);
        string word;
        string res="";
        while(ss>>word){
            string ans="";
            res+=trie->search(word,ans);
            // res+=ans;
            res+=" ";
        }
         res.pop_back();
        return res;
        
        
        
    }
};