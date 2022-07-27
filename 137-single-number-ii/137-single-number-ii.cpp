class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int res = 0;
        for(int i = 0; i <= 31; ++i) {
            int check = 1 << i, count = 0;
            for(auto child : nums) {
                if(child & check)
                    count += 1;
            }
            if(count % 3 == 1) 
                res = res | check;
        }

        return res;
    }
};