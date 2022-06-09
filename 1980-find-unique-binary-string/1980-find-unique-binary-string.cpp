class Solution {
public:
    string ans;
     unordered_map<string , int> mp;
   void solve(string &s,int n){
		if(s.size()==n){
			// cout<<s<<" ";
			 if(mp.find(s)==mp.end())
				  ans=s;
			return ;
		}
		s+='0';
		solve(s,n);
		s.pop_back(),s+='1';
		solve(s,n);
		s.pop_back();
	}
	string findDifferentBinaryString(vector<string>& nums) {
       
		for(auto &ele: nums){
			 mp[ele]++;
		}
		string s;
		solve(s,nums.size());
		return ans;
	}
};