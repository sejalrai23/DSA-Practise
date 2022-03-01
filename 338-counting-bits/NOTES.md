point 1 : if the number is even then the no of ones is equal to no of ones in the number half of it
point 2 : if number is odd then no of ones ==num of ones in prev number +1 ;
​
method-2:
Basically, it's following the 2^n rules of the binary number system. So we are taking a variable k=1, which we'll multiply with 2 after every 4 numbers. which we can check by if(k*2==i) this condition.
Finally we can put current dp[i] value by adding 1 with previous dp[i-k] value.
​
​
tc=o(n)
​