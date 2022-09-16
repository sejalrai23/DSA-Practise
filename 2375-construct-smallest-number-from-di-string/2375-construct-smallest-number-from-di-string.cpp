
 class Solution {
public:
    string smallestNumber(string pattern) {
        
        int n = pattern.size();
        
        string num = "";

        int prev = 0;
        
        for(int i=0; i<=n; i++) {
            num += (i + '1');
            if(i == n || pattern[i] == 'I') {
                reverse(num.begin() + prev, num.end());
                prev = i+1;
            }
           
        }
        
        return num;
    }
};
