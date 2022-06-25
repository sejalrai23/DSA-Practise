class Solution {
public:
    priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>>> pq;
    int recur(int num ){
        if(num==1) return 0;
        int cnt=0;
        if(num%2==0){
           cnt= 1+ recur(num/2);
        }
        else{ cnt= 1+recur(3*num+1);
        }
        return cnt;
        
    }
    int getKth(int lo, int hi, int k) {
        for(int i=lo ;i<=hi ; i++){
            int ans= recur(i);
            pq.push({ans , i});
        }
        while(k-1!=0){
            pq.pop();
            k--;
        }
        return pq.top().second;
    }
};