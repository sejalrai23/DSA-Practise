class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
       
        vector<int> m(26), curr(26), ans;
        set<char> s1;
        for(int i=0;i<p.length(); i ++){
            m[p[i]-'a']++;
        }
        for(int i=0;i<s.length(); i++){
            curr[s[i]-'a']++;
            if(i>=p.size()){
                curr[s[i-p.size()]-'a']--;
            }
            if(m==curr){
                ans.push_back(i-p.size()+1);
            }
        }
        return ans;
        
    }
};

// TC : O(S)+O(P)
// SC: O(S) +O(P)
