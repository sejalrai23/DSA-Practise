class Solution {
public:
    bool check_palindrome(string &s) {
        int left = 0;
        int right = s.size() - 1;
        
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++; right--;
        }
        
        return true;
    }
    
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> rev;
        string temp;
        
        int n = words.size();
        
        for (int i = 0; i < n; i++) {
            temp = words[i];
            reverse(temp.begin(), temp.end());
            
            rev[temp] = i;
        }
        
        vector<vector<int>> ans;
        
        if (rev.find("") != rev.end()) {
            for (int i = 0; i < n; i++) {
                if (rev[""] == i) {
                    continue;
                }
                
                if (check_palindrome(words[i])) {
                    ans.push_back({i, rev[""]});
                }
            }
        }
        
        string left, right, word;
        
        for (int i = 0; i < n; i++) {
            word = words[i];
            
            left = "";
            right = word;
            
            int sz = word.size();
            
            for (int j = 0; j < sz; j++) {
                left.push_back(word[j]);
                right.erase(0, 1);
                
                if (rev.find(left) != rev.end() && rev[left] != i && check_palindrome(right)) {
                    ans.push_back({i, rev[left]});
                }
                
                if (rev.find(right) != rev.end() && rev[right] != i && check_palindrome(left)) {
                    ans.push_back({rev[right], i});
                }
            }
        }   
        
        return ans;
    }
};