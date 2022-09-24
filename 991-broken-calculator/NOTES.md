1. reduce target value as much as possible  because this question can be done by greedy
2. if divisible by 2 divide by 2
3. else increase by 1
4. if target becomes less than startValue then only option left is to increasse
​
​
The idea is to bring target equal to startvalue & counting the number of operations.
We will do opposite insitead of turning startvalue to target.
we are turning target to startvalue by 2 steps.
if target value is odd , we will make it even by adding one to it.
If target is even we will divide by 2;
and doing these 2 operations we will count min operations till targetvalue is greater than startvalue
​
tc=o(logn) sc=o(1)