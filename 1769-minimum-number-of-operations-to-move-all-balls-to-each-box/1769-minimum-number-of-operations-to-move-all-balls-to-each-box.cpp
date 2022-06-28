class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> res(boxes.length());
        for(int i=0;i<boxes.length();i++){
            int ans=0;
            for(int j=0;j<boxes.length();j++){
                if( boxes[j]=='1'){
                   ans+=abs(j-i) ;
                }
                
            }
            res[i]=ans;
        }
        return res;
        
    }
};