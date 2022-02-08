class Solution {
public:
    int addDigits(int num) {
        while(!(num<=9 && num>=0)){
            num= num%10 + num/10;
            
        }
        return num;
    }
};