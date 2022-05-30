class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==INT_MIN && divisor==-1){
            return INT_MAX;
        }else if(dividend==INT_MIN && divisor==1){
            return INT_MIN;
        }
        bool sign=true;
        if((dividend<0 )^ (divisor<0)){ sign=false;}
        long divi=abs(dividend);
        long div=abs(divisor);
        int q=0;
        while(divi>=div){
            int cnt=0;
           while(divi-(div<<1<<cnt)>=0){
               cnt++;
           }
           q+=1<<cnt;
            divi-=div<<cnt;
            
        }
        // cout<<q<<endl;
        return sign? q:-q;
        
    }
};