class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int i=0,j=0,maxi=0;
        unordered_map<char,int> ump;
        unordered_map<string , int> count;
        
        while(j<s.length()){
            ump[s[j]]++;
            if(j-i+1<minSize){
                j++;
            }else if(j-i+1==minSize){
                if(ump.size()<=maxLetters){
                    // cout<<s.substr(i,minSize)<<endl;
                    string sub=s.substr(i,minSize);
                    count[sub]++;
                    maxi=max(maxi, count[sub]);
                    j++;
                }else if(ump.size()>maxLetters){
                    while(ump.size()>maxLetters){
                        ump[s[i]]--;
                        if(ump[s[i]]==0){
                            ump.erase(s[i]);
                        }
                        i++;
                    }
                    j++;
                }
            }else if(j-i+1>minSize){
                while(j-i+1>minSize){
                    ump[s[i]]--;
                    if(ump[s[i]]==0){
                        ump.erase(s[i]);
                    }
                    i++;
                }
                if(ump.size()<=maxLetters){
                string sub1=s.substr(i,minSize);
                // cout<<sub1<<endl;
                count[sub1]++;
                maxi=max(maxi,count[sub1]);
                }
                j++;
            }
        }
        return maxi;
        
    }
};