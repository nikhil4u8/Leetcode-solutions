/*
Brute Force:
For each request i we traverse all servers starting from i%k and check which is the next available server and schedule the task. This will take O(k) time to know which server should schedule the current job.

TIME - O(N*K) SPACE - O(K)
*/
// class Solution {
// public:
//     vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
//         vector<pair<int,int>>server(k);
//         vector<int>busy_server(k, 0);
        
//         for(int i=0;i<arrival.size();i++){
//             int temp_server = i%k;
            
//             while(temp_server < k && server[temp_server].second > arrival[i]) 
//                 temp_server++;
            
//             if(temp_server == k){
//                 temp_server = 0;
//                 while(temp_server < i%k && server[temp_server].second > arrival[i]) temp_server++;
//                 if(temp_server == i%k) continue;
//             }
            
//             server[temp_server] = {arrival[i], arrival[i] + load[i]};
//             busy_server[temp_server]++;
//         }
        
//         int maxi = 0;
//         vector<int>index;
        
//         for(int i=0;i<k;i++){
//             if(maxi < busy_server[i]){
//                 maxi = busy_server[i];
//                 index.clear();
//                 index.push_back(i);
//             }else if(maxi == busy_server[i]) index.push_back(i);
//         }
        
//         return index;
//     }
// };

class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        vector<pair<int,int>>server(k);
        vector<int>busy_server(k, 0);
        set<int>available_server;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        
        for(int i=0;i<k;i++) available_server.insert(i);
        
        for(int i=0;i<arrival.size();i++){
            int temp_server = i%k;
            int start_time = arrival[i];
            int end_time = arrival[i] + load[i];
            
            while(!pq.empty() && pq.top().first <= start_time){
                available_server.insert(pq.top().second);
                pq.pop();
            }

            if(available_server.size() == 0) continue;
            
            auto it = available_server.lower_bound(temp_server);
            if(it == available_server.end())
                it = available_server.begin();
        
            temp_server = *it;
            available_server.erase(it);
            
            pq.push({end_time, temp_server});
            busy_server[temp_server]++;
        }
        
        int maxi = 0;
        vector<int>index;
        
        for(int i=0;i<k;i++){
            if(maxi < busy_server[i]){
                maxi = busy_server[i];
                index.clear();
                index.push_back(i);
            }else if(maxi == busy_server[i]) index.push_back(i);
        }
        
        return index;
    }
};