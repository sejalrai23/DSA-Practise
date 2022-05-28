class Solution {
public:
int missingNumber(vector<int>& nums) {
int n=nums.size();
int x1=0;int x2=0;
for(int i=0;i<n;i++){
x1=x1^nums[i]; // let say array is 3,0,1 then x1 will store  3^0^1
x2=x2^(i+1);     // here x2 will store 1^2^3
}
return x1^x2;//  a^a=0 ,so the number present both in x1 and x2 will cancel out(become zero ) and the element which is not present in x1 . i.e 2 will be returned by the function.
}
};
​
​
class Solution {
public:
int missingNumber(vector<int>& nums) {
int sum = 0;
int total = nums.size()*(nums.size() + 1)/2;
for (auto number : nums) {
sum += number;
}
return total - sum;
}
};
​
​
class Solution {
public:
int missingNumber(vector<int>& nums) { // function to return missing number
int result = nums.size(); // initialize result to size of vector
int i=0; // initialize i to 0
for(int num:nums){ // for each number in vector
result ^= num; // XOR result with number
result ^= i; // XOR result with i
i++; // increment i
}
return result; // return result that is the missing number
}
};