class Solution {
public:
 vector<string> mappings = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}, ans;    
 vector<string> letterCombinations(string digits) {
	if(digits == "") return ans;  
     string combi="";// no combinations formed without any digits
	helper(digits, 0, combi);              
	return ans;
}

void helper(string &digits, int i, string &combi){	
	if(i == size(digits))  
		ans.push_back(combi);    
	else 
		for(auto c : mappings[digits[i] - '2']){
            combi+=c;
            helper(digits, i + 1, combi );
            combi.pop_back();
        }
			
}
};