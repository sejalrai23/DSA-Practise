class Solution {
public:
    int kthFactor(int n, int k) {
        priority_queue<int> pq;
        for(int i=1;i<=n ;i++){
            if(n%i==0){
                pq.push(i);
            }
            if(pq.size()>k){
                pq.pop();
            }
        }
        if(pq.size()<k) return -1;
        return pq.top();
        
    }
};