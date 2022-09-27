class StockSpanner {
public:
    stack<pair<int,int>> main;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int cnt=1;
        while(!main.empty() && main.top().first <= price){
            cnt+=main.top().second;
            main.pop();
        }
        main.push({price, cnt});
        return cnt;

        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */