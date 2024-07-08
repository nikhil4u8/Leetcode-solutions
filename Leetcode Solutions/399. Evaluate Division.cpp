class Solution {
public:
//TIME - O(M*N) SPACE - O(N)
//M is num of queries, N is num of equations
    double solve(unordered_map<string, bool>&visited, unordered_map<string, unordered_map<string, double>>&mp,
                 string num, string deno,double factor){
        
        if(mp.find(num) == mp.end()) return -1;
        if(mp[num].find(deno) != mp[num].end()) return factor * mp[num][deno];
        
        visited[num] = true;
        for(auto it : mp[num]){
            if(!visited[it.first]){
                visited[it.first] = true;
                
                double ans = solve(visited, mp, it.first, deno, factor * it.second);
                if(ans != -1) return ans;
            }
        }
        
        return -1;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        //SPACE - O(N)
        unordered_map<string, unordered_map<string, double>>mp;
        
        //TIME - O(N)
        for(int i=0;i<equations.size();i++){
            mp[equations[i][0]][equations[i][1]] = values[i];
            mp[equations[i][1]][equations[i][0]] = 1/values[i];
        }
        
        vector<double>ans;
        
        //TIME - O(M*N)
        for(int i=0;i<queries.size();i++){
            unordered_map<string, bool>visited;
            string src = queries[i][0];
            string dest = queries[i][1];
            
            double res = solve(visited, mp, src, dest, 1);
            ans.push_back(res);
        }
        
        return ans;
    }
};