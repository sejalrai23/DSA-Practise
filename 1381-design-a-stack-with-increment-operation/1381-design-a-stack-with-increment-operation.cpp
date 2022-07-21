class CustomStack {
public:
    vector<int> vec;
    int n;
    CustomStack(int maxSize) {
       n=maxSize;
    }
    
    void push(int x) {
        int s=vec.size();
        if(s<n){
          vec.push_back(x);
        }
        
    }
    
    int pop() {
        
        if(vec.size()==0) return -1;
        int ans=vec[vec.size()-1];
        vec.pop_back();
        // cout<<ans<<"-"<<vec.size()<<endl;
        return ans;
    }
    
    void increment(int k, int val) {
      
        for(int i=0;i<k && i<vec.size() ;i++){
            // cout<<vec[i]<<endl;
            vec[i]+=val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */