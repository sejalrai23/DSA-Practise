struct Node{
    int key, value, cnt;
    Node* next;
    Node* prev;
    Node(int _key , int _val){
        key=_key;
        value=_val;
        cnt=1;
    }
};
struct List{
    int size;
    Node* head;
    Node* tail;
    List(){
        head= new Node(0,0);
        tail= new Node(0,0);
        head->next=tail;
        tail->prev=head;
        size=0;
    } 
    
    void addFront(Node* node){
        Node  *temp=head->next;
        node->next=temp;
        node->prev=head;
        head->next=node;
        temp->prev=node;
        size++;      
    }
    
    void removeNode(Node* delnode){
        Node* delprev=delnode->prev;
        Node* delnext=delnode->next;
        delprev->next=delnext;
        delnext->prev=delprev;
        size--;
    }
};
class LFUCache {
public:
    map<int, Node*> keyNode;
    map<int , List*> freqList;
    int maxSize , minFreq , currSize;
    LFUCache(int capacity) {
        maxSize=capacity;
        minFreq=0;
        currSize=0;    
    }
    
    void updateFreqList(Node* node){
        keyNode.erase(node->key);
        freqList[node->cnt]->removeNode(node);
        if(node->cnt==minFreq && freqList[node->cnt]->size==0){
            minFreq++;
        }
        List* nextHighFreqList=new List();
        if(freqList.find(node->cnt+1)!=freqList.end()){
            nextHighFreqList=freqList[node->cnt+1];
        }
        node->cnt+=1;
        nextHighFreqList->addFront(node);
        freqList[node->cnt]=nextHighFreqList;
        keyNode[node->key]=node;
    }
    
    int get(int key) {
        if(keyNode.find(key)!=keyNode.end()){
            Node* node=keyNode[key];
            int res=node->value;
            updateFreqList(node);
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(maxSize==0){
            return ;
        }
        if(keyNode.find(key)!=keyNode.end()){
            Node* node=keyNode[key];
            node->value=value;
            updateFreqList(node);
        }
        else{
            if(currSize==maxSize){
                List* list=freqList[minFreq];
                keyNode.erase(list->tail->prev->key);
                freqList[minFreq]->removeNode(list->tail->prev);
                currSize--;
            }
            currSize++;
            minFreq=1;
            List* listFreq=new List();
            if(freqList.find(minFreq)!=freqList.end()){
                listFreq=freqList[minFreq];
            }
            Node* node=new Node(key,value);
            listFreq->addFront(node);
            keyNode[key]=node;
            freqList[minFreq]=listFreq;
        }
        
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */