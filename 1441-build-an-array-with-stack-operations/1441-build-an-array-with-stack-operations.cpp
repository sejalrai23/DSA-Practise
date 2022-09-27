class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int end=target[target.size()-1];
        int k=0;
        vector<string> ans;
        for(int i=1;i<=end;i++){
            if(target[k]==i){
                ans.push_back("Push");
                k+=1;
            }else{
                ans.push_back("Push");
                ans.push_back("Pop");
            }
            
        }
        return ans;
        
    }
};