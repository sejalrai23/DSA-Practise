class MyQueue {
public:
    stack<int> input;
    stack<int> output;
    MyQueue() {
        
        
    }
    
    void push(int x) {
        input.push(x);
        
    }
    
    int pop() {
        if(!output.empty()){
           int val=output.top();
            output.pop();
            return val;
        }
        while(!input.empty()){
            output.push(input.top());
            input.pop();
                
        }
        int val=output.top();
        output.pop();
        return val;
    }
    
    int peek() {
        if(!output.empty()){
           int val=output.top();
           
            return val;
        }
        while(!input.empty()){
            output.push(input.top());
            input.pop();
                
        }
        int val=output.top();
   
        return val;
        
        
    }
    
    bool empty() {
        return input.empty() && output.empty();
        
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */