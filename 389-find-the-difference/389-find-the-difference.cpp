class Solution {
public:
    char findTheDifference(string s, string t) {
        map<char, int> m1;
        for(int i=0; i <s.length();i++){
            m1[s[i]]++;
        }
        for(int i=0; i <t.length();i++){
            m1[t[i]]++;
        }
        char ans;
       for(auto it : m1){
           if(it.second%2==1){
               ans=it.first;
           }
       }
        
        
               
    
        return ans;
       
    }
};