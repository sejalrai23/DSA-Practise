class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> vec= {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        map<string, int> mp;
        for(auto it: words){
            string res="";
            
            for(int i=0;i<it.length();i++){
                res+= vec[it[i]-'a'];
            }
            
            mp[res]++;
        }
       
        return mp.size();
    }
};