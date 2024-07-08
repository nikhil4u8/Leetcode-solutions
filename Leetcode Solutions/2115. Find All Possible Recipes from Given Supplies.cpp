/*
Check if this graph is a DAG or not?
1. No cycle
2. Check if all basic ingredients are available in supplies or not?
3. Do topological sort, and return the order in which recipe should be made
*/
class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        
        int n = recipes.size();
        unordered_map<string, vector<string>>rev_graph;
        unordered_map<string, int>indegree;
        
        for(int i=0;i<n;i++){
            indegree[recipes[i]] += ingredients[i].size();
            
            for(int j=0;j<ingredients[i].size();j++)
                rev_graph[ingredients[i][j]].push_back(recipes[i]);
            
        }
        for(int i=0;i<supplies.size();i++) 
            indegree[supplies[i]] += 0;
        
        queue<string>q;
        
        for(auto it : indegree){
            if(it.second == 0) q.push(it.first);
        }
        
        vector<string>res;
        while(!q.empty()){
            string src = q.front(); q.pop();
            
            for(int i=0;i<rev_graph[src].size();i++){
                string child = rev_graph[src][i];
                indegree[child]--;
                if(indegree[child] == 0){
                    q.push(child);
                    res.push_back(child);
                }
            }
        }
        
        return res;
    }
};