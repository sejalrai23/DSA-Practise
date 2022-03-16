class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int b=0;
        stack<int> s;
        for(int i=0;i<pushed.size();i++){
            s.push(pushed[i]);
            while(!s.empty() && s.top()==popped[b]){
                s.pop();
                b++;
            }
        }
        return s.empty();
    }
};