class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int,int> m;
        int rem=arr.size()/2;
        for(int i=0;i<arr.size();i++){
            m[arr[i]]++;
            if(m[arr[i]]>=rem){
                return 1;
            }
        }
         priority_queue<int> g ;
        for(auto it :m){
            g.push(it.second);
        }
        int min=0,cnt=0;
        while(!g.empty()){
            min+=g.top();
            cnt++;
            if(min>=rem){
                break;
            }
            g.pop();
        }
        return cnt;
        
    }
};