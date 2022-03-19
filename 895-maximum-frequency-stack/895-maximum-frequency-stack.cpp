
class FreqStack {
public:
    int i=0;
    priority_queue< pair <pair<int,int> ,int> >q;
    unordered_map<int,int>m;   
   void push(int val) {
      i++;
      m[val]++;
      q.push({{m[val],i},val});
}

int pop() {
    int x=q.top().second; q.pop();
    m[x]--;
   return x;
}
};


/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */