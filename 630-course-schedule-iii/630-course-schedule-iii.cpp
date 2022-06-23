class Solution {
public:
    static bool cmp(vector<int>a , vector<int> b){
        return a[1]< b[1];
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), cmp);
        int x=0, cnt=0;
        priority_queue<int> pq;
        for(auto it: courses){
            if(it[0]<=it[1]){
            x+= it[0];
            cout<<x<<endl;
            if(x<=it[1]){
                cnt++;
                pq.push(it[0]);
            }else{
                if(pq.top()>it[0]){
                    x-=pq.top();
                    pq.pop();
                    pq.push(it[0]);
                }else{
                    x-=it[0];
                }
            }
            }
            
        }
        return cnt;
        
    }
};