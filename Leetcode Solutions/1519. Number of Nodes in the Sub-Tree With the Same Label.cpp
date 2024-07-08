/*
Build the graph, and then having a freq map which will store freq of elements in the subtree, and 
in ans we'll store just the freq of current elements retrieved from it's subtree using freq map
*/
class Solution {
public:
//TIME - O(26*N) SPACE - O(26*N)
//Since we're visiting each node only once, and we're merging freq map so time complexity is O(26*N)
//We can't have more than N elements in DFS recrusive stack, and 26 space for freq array, hence
//space complexity - O(26*N)
    vector<int>ans;
    vector<int> nodeFreq(unordered_map<int, vector<int>>&graph, string &labels, int node, int parent){
        vector<int>freq(26, 0);
        freq[labels[node] - 'a'] = 1;

        if(graph[node].size() == 0) return freq;

        for(int i=0;i<graph[node].size();i++){
            int temp_node = graph[node][i];
            if(temp_node == parent) continue;

            vector<int>temp_freq = nodeFreq(graph, labels, temp_node, node);
            for(int i=0;i<26;i++) freq[i] += temp_freq[i];
        }

        ans[node] = freq[labels[node] - 'a'];
        return freq;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        ans = vector<int>(n, 1);
        unordered_map<int, vector<int>>graph;
        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }

        nodeFreq(graph, labels, 0, -1);

        return ans;
    }
};