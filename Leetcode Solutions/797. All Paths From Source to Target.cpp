/*
Desc :-
    - A DAG is given, return all possible unique path from node 0 to n-1

Ques to ask :-
    - can this graph form a cycle? Can there be reverse edge / self loops?
    - can there be 0 nodes? / single node present?
    - Can we've multiple root node?
    
Sol :
BEST APPROACH
=> Using Recursion : [TIME - O(2^N * N) | SPACE - O(N) -> recursive stack]
-> TC EXPLANATION : See at last
    - Recursively start traversing from start to end node & once start == 
    end, then we found a path so push it to ans vector
*/
class Solution {
public:
    vector<vector<int>>ans;
    //since it's a DAG, so we dom't need to take care of duplicate path, 
    //becoz if there is no reverse edge (not DAG) so can't make cycles, 
    //hence no duplicate path.
    void findAllPath(vector<vector<int>>&graph, int start, int end, vector<int>tempPath){
        tempPath.push_back(start);
        if(start == end){ ans.push_back(tempPath); return; }

        for(int i=0;i<graph[start].size();i++){
            int node = graph[start][i];
            findAllPath(graph, node, end, tempPath);
        }
        tempPath.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        findAllPath(graph, 0, n-1, {});

        return ans;
    }
};
/*
TC EXPLANATION :
At max there could be 2^(n-1)-1 path possible b/w 0 to n-1 [sum of 2^i 
from i=0 to i=n-2 meaning each node can have 2 choices (either to take it 
or not) except 0/n-1 node, so we're left with n-2 node, so with 1 node in 
between 0/n-1 we've 2 path i.e 2^1, with 0 node in b/w we've 2^0 = 1 path 
possible, like that summing until we've n-2 nodes in b/w which is 
2^(n-1) - 1]. Now with N-2 nodes in between, it'll take O(N) time to build a path.
So for 2^(n-1) - 1 paths, it'll take O(2^(n-1)-1)*O(n) time = O(2^N*N) time.
*/