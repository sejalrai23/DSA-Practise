class Solution {
public:
    long long minimumReplacement(vector<int>& num) {
        
        int len = num.size(), right = num[len-1];
        long long res =0 , brk ;
        
        for(int i=len-2;i>=0;i--){
            if(right>=num[i])
                right = num[i];
            else{
                brk = ((num[i]-1)/right)+1;
                right = num[i]/brk;
                res +=(brk-1);
            }       
        }
        return res;    
    }
};