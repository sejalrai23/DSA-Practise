class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        int size = bank.size(); 
        unordered_map<string, int> mp; 
        for(int i = 0; i < size; i++) 
        {
           mp[bank[i]]++;
        }
        if(mp.find(end) ==mp.end())
        {
            return -1;
        }

        vector<char> available = {'A', 'C', 'G', 'T'};  
        int ans = 0; 
        queue<string> q; 
        q.push(start); 
        while(!q.empty())
        {
            int n = q.size(); 
            while(n--)
            {
                string curr = q.front(); 
                q.pop();
                
                if(curr == end)
                {
                    return ans;
                }
                mp.erase(curr);
                for(int i = 0; i < 8; i++)
                {
                    char orig = curr[i]; 
                    for(int j = 0; j < 4; j++) 
                    {   
                        curr[i] = available[j];
                        if(mp.find(curr) != mp.end())
                        {
                                q.push(curr);
                        }
                    }
                    curr[i] = orig;
                }
            }
            ans++; 
        }
        
        return -1; 
    }
};