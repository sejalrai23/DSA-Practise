we will ceck for half string only as it is palindrome rest half will be checked automatically so if we find all halfs in frst part then we replace last char of string to b and if we find a char in first half not equal to a then we simply make it a .
as to make it lexicographically less we try to replace it will minimum values only .
why check only for half :
cases like :
aaabaaa here if we do for entire string then b at midddle of string gets replaced by a hance resultant becomes palindrome again so we chack only for half .