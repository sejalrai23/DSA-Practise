We can come up with the formula
​
spaceNum = (n-1)*2 + 1
result = 1 + 2 + ... + spaceNum = spaceNum * (spaceNum+1) / 2
Hence, in case n = 2
​
spaceNum = (n-1)*2 + 1 = (2-1) * 2 + 1 = 3
result = spaceNum * (spaceNum+1) / 2 = 3 * 4 / 2 = 6
Result: 6
​
Case: n = 3
​
Place P3 D3 to 6 results from case n=2: (__ P2 __ D2 __ P1 __ D1 __), (__ P2 __ P1 __ D2 __ D1 __),..., (__ P1 __ D1 __ P2 __ D2 __)
Hence, in case n = 3
spaceNum = (n-1)*2 + 1 = (3-1)*2 + 1 = 5
result = spaceNum * (spaceNum+1) / 2 = 5 * 6 / 2 = 15
// Apply this P3 D3 place to 6 results from case n = 2
// result = 15 * 6 = 90
Result: 90