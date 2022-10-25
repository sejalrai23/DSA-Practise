class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string ans1="", ans2="";
        for(auto it: word1){
            ans1+=it;
        }
        for(auto it: word2){
            ans2+=it;
        }
        return ans1==ans2;
    }
};