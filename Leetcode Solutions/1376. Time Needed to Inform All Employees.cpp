class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int,vector<int>>employee;
        
        for(int i=0;i<manager.size();i++) employee[manager[i]].push_back(i);
        
        int max_time = 0;
        queue<pair<int,int>>q;
        vector<bool>visited(n, false);
        
        q.push({headID, 0});
        
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto temp = q.front();
                q.pop();
                
                int manager_id = temp.first;
                int time = temp.second;
                
                max_time = max(max_time, time);
                
                for(int i=0;i<employee[manager_id].size();i++){
                    int employee_id = employee[manager_id][i];

                    if(!visited[employee_id]){
                        visited[employee_id] = true;
                        q.push({employee_id, time + informTime[manager_id]});
                    }
                }   
            }
        }
        
        return max_time;
    }
};