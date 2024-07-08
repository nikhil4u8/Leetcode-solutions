class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        unordered_map<int, vector<int>>graph;
        vector<int>indegree(n, 0);
        
        for(int i=0;i<relations.size();i++){
            graph[relations[i][0]-1].push_back(relations[i][1]-1);
            indegree[relations[i][1]-1]++;
        }
        
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i] == 0)
                q.push(i);
        }
        
        int sem = 0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int node = q.front(); q.pop();
                
                for(int i=0;i<graph[node].size();i++){
                    int child = graph[node][i];
                    indegree[child]--;
                    if(indegree[child] == 0)
                        q.push(child);
                }
            }
            sem++;
        }
        
        for(int i=0;i<n;i++){
            if(indegree[i] != 0) return -1;
        }
        return sem;
    }
};