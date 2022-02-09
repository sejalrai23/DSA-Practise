class BrowserHistory {
public:
    list<string> h;
    list<string> :: iterator it;
    BrowserHistory(string homepage) {
        h.push_back(homepage);
        it=h.begin();
    }
    
    void visit(string url) {
        auto del= it;
        del++;
        h.erase(del,h.end());
        h.push_back(url);
        it++;
        
    }
    
    string back(int steps) {
        while(it!=h.begin() && steps--){
            it--;
        }
        return *it;
        
    }
    
    string forward(int steps) {
        while(it!=(--h.end()) && steps--){
            it++;
        }
        return *it;
        
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */