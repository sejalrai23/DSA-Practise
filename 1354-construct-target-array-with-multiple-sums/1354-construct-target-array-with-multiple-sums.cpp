class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int> pq;
        long long sum = 0;
        for(auto num : target){
            pq.push(num);
            sum+=num;
        }
        while(pq.top() != 1){
            sum -= pq.top();
            if(sum == 0 || sum >= pq.top()) return false;  //cases like [2,3,4]
            int old = pq.top()%sum;
            if(sum != 1 && old == 0) return false;   //cases like [2,4]
            pq.pop();
            pq.push(old);
            sum += (old);
        }
        return true;
    }
};