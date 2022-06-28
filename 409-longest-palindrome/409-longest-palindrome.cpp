class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char , int> ump;
        for(auto it:s){
            ump[it]++;
        }
        int flag=0, ans=0;
        for(auto it : ump){
            if(it.second%2==0){
                ans+=it.second;
            }else{
               
                 flag = 1;
                 ans+=it.second-1;
            }
        }

        if(flag) ans+=1;
        return ans;
        
    }
};