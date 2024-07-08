/*
SHORT EXPLAIN
Suppose we take 2 pointers, from the leaf node, and start traversing 
inwards with the same speed, if 2 pointers meets then we have one 
centroid or one root node, if the pointers face each other then we have 
2 centroid or 2 root nodes

DETAILED EXPLAIN
Suppose we don't know n, nor do we have random access of the nodes. We 
have to traversal. It is very easy to get the idea of two pointers. One 
from each end and move at the same speed. When they meet or they are one 
step away, (depends on the parity of n), we have the roots we want.

For a tree we can do some thing similar. We start from every end, by end 
we mean vertex of degree 1 (aka leaves). We let the pointers move the same 
speed. When two pointers meet, we keep only one of them, until the last 
two pointers meet or one step away we then find the roots.

It is easy to see that the last two pointers are from the two ends of 
the longest path in the graph.

TIME - O(N) SPACE - O(N)
V = N & E = N-1
*/
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int>indegree(n, 0);
        unordered_map<int, vector<int>>graph;
        
        for(int i=0;i<edges.size();i++){
            indegree[edges[i][0]]++;
            indegree[edges[i][1]]++;
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        
        queue<int>q;
        
        for(int i=0;i<n;i++){
            if(indegree[i] == 1)
                q.push(i);
        }
        
        int first_root = 0, second_root = 0;
        while(!q.empty()){
            if(q.size() <= 2) first_root = q.front();
            int size = q.size();
            while(size--){
                int node = q.front(); q.pop();
                
                for(int i=0;i<graph[node].size();i++){
                    int child = graph[node][i];
                    indegree[child]--;
                    if(indegree[child] == 1)
                        q.push(child);
                }
                
                second_root = node;
            }
        }
        
        if(first_root == second_root) return {first_root};
        return {first_root, second_root};
    }
};