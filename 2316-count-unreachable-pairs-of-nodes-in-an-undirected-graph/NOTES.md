Total no. of ways to pick 2 nodes from n nodes = nC2 = n*(n-1)/2;
Here we should not pick 2 nodes from the same component, so we find the number of nodes in each component. And subtract the no. of ways to pick 2 nodes from that component.
To find no. of nodes in a component, we can just do a DFS traversal and maintain a cnt to maintain no. of nodes visited in that dfs call.
​
**we cnt nodes in a comp and find pairs cnt*cnt-1/2 and then subtract from total pairs which is n*n-1/2 for every component!**