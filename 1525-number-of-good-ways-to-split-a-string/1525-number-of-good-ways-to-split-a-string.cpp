class Solution {
public:
    int numSplits(string s) {
        unordered_map<char,int> m1;
        unordered_map<char , int> m2;
        int cnt=0;
        for(auto it:s){
            m1[it]++;
        }
        
        for(auto it : s){
            m1[it]--;
            if(m1[it]==0) m1.erase(it);
            m2[it]++;
            if(m1.size()==m2.size()) cnt++;
        }
        return cnt;
    }
};