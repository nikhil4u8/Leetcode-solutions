#define ppi pair<int,pair<int,int>>
class Solution {
public:
    //TIME - O(N*MlogM) SPACE - O(M)
    //M - len(server)
    //N - len(tasks)
//     vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
//         set<vector<int>>available_server;
        
//         for(int i=0;i<servers.size();i++)
//             available_server.insert({servers[i], i, 0});
        
//         vector<int>ans;
        
//         for(int i=0;i<tasks.size();i++){
//             vector<int>curr_server;
            
//             set<vector<int>> :: iterator temp_it;
//             bool flag = false;
//             int min_time = INT_MAX;
//             int _wt, _idx;
            
//             for(auto it : available_server){
//                 if(it[2] <= i){
//                     int wt = it[0];
//                     int idx = it[1];
//                     int time = it[2];
                    
//                     ans.push_back(idx);
//                     available_server.erase(it);
//                     available_server.insert({wt, idx, max(i, time) + tasks[i]});
                    
//                     flag = true;
//                     break;
//                 }
                
//                 if(min_time > it[2]){
//                     min_time = it[2];
//                     _wt = it[0];
//                     _idx = it[1];
//                 }
//             }
            
//             if(flag) continue;
            
//             ans.push_back(_idx);
//             temp_it = available_server.find({_wt, _idx, min_time});
//             available_server.erase(temp_it);
//             available_server.insert({_wt, _idx, max(i, min_time) + tasks[i]});
//         }
        
//         return ans;
//     }
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        set<pair<int,int>>available_server;
        priority_queue<ppi, vector<ppi>, greater<ppi>>pq;
        vector<int>ans;
        
        for(int i=0;i<servers.size();i++) available_server.insert({servers[i], i});
        
        for(int i=0;i<tasks.size();i++){
            while(!pq.empty() && pq.top().first <= i){
                int wt = pq.top().second.first;
                int idx = pq.top().second.second;
                
                available_server.insert({wt, idx});
                pq.pop();
            }
            
            int wt, idx, time;
            if(available_server.size() == 0){
                auto curr = pq.top();
                pq.pop();
                
                time = curr.first;
                wt = curr.second.first;
                idx = curr.second.second;
            }else{
                auto curr = available_server.begin();
                time = i;
                wt = curr->first;
                idx = curr->second;
                
                available_server.erase(curr);
            }
            
            ans.push_back(idx);
            pq.push({time + tasks[i], {wt, idx}});
        }
        return ans;
    }
};