dp[i] will store the score if I start jumping from index i and priority queue will store all the scores of the window [i+1, min(n-1, i+k)].
To get the maximum score from index i, I should jump to next index with the maximum value in the window.
​
https://leetcode.com/problems/jump-game-vi/discuss/2257235/C%2B%2B-DP-or-Recursive-or-Memoization-or-Tabulation-or-Max-Heap