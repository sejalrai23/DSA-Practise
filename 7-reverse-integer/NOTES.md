Because if he doesn't 'divide by 10', then the program will execute 'else' statement.
In 'else' statement, 'y' will be multiplied by 10, if 'y' happens to overflow at that statement, the program will fail & close.
​
Eg:
INT_MAX size is 2,147,483,647
Imagine 'y' value is 746,384,741
If I don't put the 'divide by 10' in 'if' statement, the program will execute 'else' statement
In 'else' statement, 'y' will be muliplied by 10, result in 7,463,847,410 (more than 2,147,483,647), which causes INT overflow error, the program will exit.
​
tl;dr
The point of this is to check whether 'y' will overflow before you multiply it by 10.