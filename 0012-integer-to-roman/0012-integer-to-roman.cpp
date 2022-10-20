class Solution {
public:
    string intToRoman(int num) {
     vector<int> v1={1000,900,500,400,100,90,50,40,10,9,5,4,1};
     vector<string> v2={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
     string ans;
     for(int i=0;num!=0;i++){
         while(num>=v1[i]){
             num-=v1[i];
             ans+=v2[i];
         }
     }
        return ans;   
    }
};