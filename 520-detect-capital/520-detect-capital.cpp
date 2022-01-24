class Solution {
public:
    bool detectCapitalUse(string word) {
        vector<char> lower;
        vector<char> caps;
        for(int i=1; i<word.length();i++){
            if(word[i]<=122 && word[i]>=97){
                lower.push_back(word[i]);
            }else{
                caps.push_back(word[i]);
            }
        }
        if(word[0]>=65 && word[0]<=90){
            if(lower.size()==word.length()-1 && caps.size()==0){
                return true;
            }
            else if(caps.size()==word.length()-1 && lower.size()==0){
                return true;
            }
        }
        else{
            if(word[0]>=97 && word[0]<=122 && lower.size()==word.length()-1){
                return true;
            }
        }
        return false;
        
    }
};