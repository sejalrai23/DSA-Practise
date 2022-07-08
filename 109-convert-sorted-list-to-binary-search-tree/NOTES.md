Time complexity: O(n log(n)).
There are log(n) recursive levels because each time we split it to half, and in each level we loop through the whole list, divided into small parts.
Space complexity: O(log(n)).
We don't consider the returning tree as extra space, but we have log(n) recursive calls on stack.