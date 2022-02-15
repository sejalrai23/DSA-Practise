class Solution {
public:
    int calPoints(vector<string>& ops) {
        int sum=0;
        stack<int> s;
        for(int i=0 ; i <ops.size();i++){
        //     if(s.empty()){
        //         s.push(stoi(ops[i]));
        //     }
           
           if(ops[i]=="C"){
                sum-=s.top();
                s.pop();
            }
            else if(ops[i]=="D"){
                // cout<<s.top()<<endl;
                s.push(2*s.top());
                sum+=s.top();
                
            }
            else if(ops[i]=="+"){
                int val1=s.top();
                s.pop();
                int val2= s.top();
                s.pop();
                s.push(val2);
                s.push(val1);
                s.push(val1+val2);
                // sum+=s.top();
                // s.pop();
                // sum+=s.top();
                // s.pop();
                sum+=s.top();
                
                
            }else{
               
                
                s.push(stoi(ops[i]));
                sum+=s.top();
          
            }
            // cout<<sum<<endl;
        
        }
        return sum;
        
    }
};