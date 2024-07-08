/*
Desc :- Print all the children of a given node.

Ques to ask :-
    - What to do when there is a cycle?
    - Can there be a self loop, like pid[i] == ppid[i]?
    - Can there be multiple root node?
    - If tree is empty? Can one node have multiple parents
*/

//TIME - O(N) SPACE - O(N)
class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        //parent -> {childrens}
        unordered_map<int, vector<int>>graph;

        for(int i=0;i<ppid.size();i++) graph[ppid[i]].push_back(pid[i]);
        
        vector<int>ans;

        queue<int>q;
        q.push(kill);

        while(!q.empty()){
            int size = q.size();
            while(size--){
                int curr = q.front(); q.pop();
                ans.push_back(curr);

                for(int i=0;i<graph[curr].size();i++){
                    int kill_child = graph[curr][i];
                    q.push(kill_child);
                }
            }
        }

        return ans;
    }
};