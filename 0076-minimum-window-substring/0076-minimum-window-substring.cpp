class Solution {
public:
    string minWindow(string s, string s1) {
        if(s1.length()>s.length()) return "";
        unordered_map<char,int> mp;
    for(int i=0 ; i<s1.length();i++){
     mp[s1[i]]++;
    }

//Creating Variables

    int ans=INT_MAX;
    int i=0,j=0;
    int count=mp.size();

// starting to  solve
        
   int st =0, end=0;

    while(j<s.length())
    {
      // CALCULATION STEP ( As Aditya's general format)

       if(mp.find(s[j])!=mp.end())
       {
           mp[s[j]]--;
           if(mp[s[j]]==0)
           count--;
       }

// step to slide " j "

       if(count>0)
       j++;

// step where we will find a candidate for answer

       else if(count==0)
       {
           if(j-i+1<ans) {
               ans=j-i+1;
               st=i;
               end=j+1;
           }    // A candidate for our Answer

// trying to minimize the window size after getting a candidate for answer

           while(count==0)
           {
               if(mp.find(s[i])==mp.end())
               {
                   i++;
                    if(j-i+1<ans) {
               ans=j-i+1;
               st=i;
               end=j+1;
           }   
               }
               else
               {
                   mp[s[i]]++;
                   if(mp[s[i]]>0)
                   {
                       i++;
                       count++;
                   }
                   else
                   {
                       i++;
                        if(j-i+1<ans) {
               ans=j-i+1;
               st=i;
               end=j+1;
           }   // updating the answer
                   }
               }
           }
           j++;
       }
        
    }
        cout<<ans<<"-"<<st<<"-"<<end<<endl;
        return ans==INT_MAX ? "" : s.substr(st, end-st);
    }
};