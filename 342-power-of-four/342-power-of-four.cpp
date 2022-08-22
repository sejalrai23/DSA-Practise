class Solution {
public:
    bool isPowerOfFour(int n) {
        while(n){
           if(n==1) return true;
           if(n%4==0){
               n/=4;
           }else{
               break;
           }
        }
        return false;
    }
};