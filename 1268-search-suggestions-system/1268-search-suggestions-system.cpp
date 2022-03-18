struct Node{
    Node* links[26];
    vector<string> bags[26];
    bool ContainsKey(char ch){
        return (links[ch-'a']!=NULL);
    }
    
    Node* getChar(char ch){
        return links[ch-'a'];
    }
    
    void put(char ch, Node* root){
        links[ch-'a']=root;
    }
    
};

class Trie{
private: Node* root;
public:
    
    Trie(){
        root= new Node();
    }
    
    void insert(string& word){
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->ContainsKey(word[i])){
                node->put(word[i],new Node());
            }
            node->bags[word[i]-'a'].push_back(word);
            
            node=node->getChar(word[i]);
        }
    }
    void search(string & word,vector<vector<string>> &ans){
        Node* curr=root;
        bool pre=false;
        for(auto c:word){
            if(pre || curr->ContainsKey(c)==false){
                ans.push_back({});
                pre=true;
            }else{
                sort(curr->bags[c-'a'].begin(),curr->bags[c-'a'].end());
                if(curr->bags[c-'a'].size()<=3){
                    ans.push_back(curr->bags[c-'a']);
                }else{
                    vector<string> temp(curr->bags[c-'a'].begin(),curr->bags[c-'a'].begin()+3);
                    ans.push_back(temp);
                }
                curr=curr->getChar(c);
            }
           
        }
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
         vector<vector<string>> ans;
        Trie* root=new Trie();
        for(auto w:products){
            root->insert(w);
            
        }
        root->search(searchWord,ans);
        return ans;
    }
};