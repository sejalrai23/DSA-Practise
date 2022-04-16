The idea is to find the max sum subbary of given size firstlen and seconlen seperately
Find prefix sum for firstlen and suffix sum for secondLen and vice-versa
Dp1-> it will store the max sum of the subarray of size firstlen from 0th to ith index.
Dp2-> it will store the max sum of the subarray from last index to ith index
and then check from a window of fisrstlen-1 to nums.size()- secondlen
which ever has the max sum will be our result
​
​