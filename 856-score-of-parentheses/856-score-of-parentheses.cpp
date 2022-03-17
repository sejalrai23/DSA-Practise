class Solution {
public:
int scoreOfParentheses(string s)
{
    stack<int> stck;
    stck.push(0);
    for(char c:s){
        if(c=='(')
            stck.push(0); 
        else{
            int res=stck.top(); 
            stck.pop();
            int val=0;
            if(res>0)
                val=res*2;
            else 
                val=1;
            stck.top()+=val; 
        }   
    }
    return stck.top();
}
};