// class Solution {
// public:
//     int addDigits(int num) {
//         while(!(num<=9 && num>=0)){
//             num= num%10 + num/10;
            
//         }
//         return num;
//     }
// };

//TC= O(logn)

class Solution {
public:
    int addDigits(int num) {
      if(num==0)
          return 0;
      else if(num%9==0)
          return 9;
      else
          return num%9;
    }
};
// UPDATE : The O(1) approach method is called Digit Root. Check it out.