class Solution {
public:
    vector<string> getGrayCode(int n){
        if(n==0) return {"0"};
        if(n==1) return {"0","1"};
        
        vector<string> temp=getGrayCode(n-1);
        vector<string> ans;
        
        for(auto it: temp){
            ans.push_back('0'+it);
        }
        reverse(temp.begin(),temp.end());
         for(auto it: temp){
            ans.push_back('1'+it);
        }
        return ans;
        
    }
    vector<int> grayCode(int n) {
        vector<string> res=getGrayCode(n);
        vector<int> ans;
        for(auto it: res){
            ans.push_back(stoi(it, 0, 2));
        }
        return ans;
    }
};