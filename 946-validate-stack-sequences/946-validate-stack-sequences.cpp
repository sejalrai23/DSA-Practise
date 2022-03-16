class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int b=0,a=0;
        stack<int> s;
        while(a<pushed.size() && b<popped.size()){
            if(pushed[a]==popped[b]){
                a++;
                b++;
            }else{
                if(!s.empty() && s.top()==popped[b]){
                    s.pop();
                    b++;
                }else{
                    s.push(pushed[a]);
                    a++;
                }
            }
        }
        // cout<<b<<endl;
        while(!s.empty() && b<popped.size()){
            if(s.top()==popped[b]){
                s.pop();
                b++;
            }
            else{
                b++;
            }
        }
        return s.empty();
    }
};