You are given a directed acyclic graph as a list of pairs, where the 
first element is a source node and the second element the destination 
node. Write a function that takes two nodes and returns whether they 
have a common ancestor or not.

Example 1:
Input: ([[A, B], [A, C], [A, D], [B, G], [E, F]] ; B; G)
Output: True

Example 2:
Input: ([[A, B], [A, C], [A, D], [B, G], [E, F]] ; B; F)
Output: False

/*
Sol :
Build a map<Node, Node> to keep track of each Node's parent, and then 
the problem essentially becomes an LCA III (with parent pointers).

Ref : 1650. Lowest Common Ancestor of a Binary Tree III
*/