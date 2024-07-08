class Solution {
public:
// smallest processing time -> smallest index
//TIME - O(NlogN) SPACE - O(N)
/*
--> Indexing all the tasks so they dont loose their identity while c
alculating the answer.
--> Sort the tasks.
--> Keep pushing tasks into queue while the enqueueing time of next 
task is lower than the current time.
--> If queue is empty and still the outer loop is running...then this 
means we still have tasks and also the queue is empty ---> CPU is idle 
from 't'(current time) to tasks[i][0](next enqueueing time).
--> If queue is not empty and also the next enqueueing time is greater 
than curr time!! that means we do the task having shortest burst time 
untill our current time is equal of greater than the enqueueing time 
of next task.
--> While poping from queue, keep pushing every index in answer vector.
*/
    vector<int> getOrder(vector<vector<int>>& tasks) {
        for(int i=0;i<tasks.size();i++) tasks[i].push_back(i);
        sort(tasks.begin(), tasks.end());

        priority_queue<vector<long long int>, vector<vector<long long int>>, greater<vector<long long int>>>pq;
        vector<int>ans;
        long long int end = 0, start = 0, j = 0;

        for(int i=0;i<tasks.size();i++){
            while(j < tasks.size()){
                int enque_time = tasks[j][0];
                int temp_enque_time = tasks[i][0];
                int process_time = tasks[j][1];
                int idx = tasks[j][2];

                if(enque_time <= end) 
                    pq.push({process_time, idx, enque_time});
                else if(enque_time == temp_enque_time)
                    pq.push({process_time, idx, enque_time});
                else break;
                j++;
            }

            vector<long long int>curr_task = pq.top();
            pq.pop();

            long long int curr_enque_time = max(end, curr_task[2]);
            end = max(end, curr_enque_time + curr_task[0]);
            ans.push_back(curr_task[1]);
        }

        return ans;
    }
};

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        unordered_map<string,deque<int>>index;
        
        for(int i=0;i<tasks.size();i++){
//             int enque_time = tasks[i][0];
//             int process_time = tasks[i][1];
//             string key = to_string(enque_time) + ',' + to_string(process_time);
            
//             index[key].push_back(i);
            tasks[i].push_back(i);
        }
        
        sort(tasks.begin(), tasks.end());
        int curr_time = tasks[0][0];
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>pq;
        
        vector<int>ans;
        
        for(int i=0;i<tasks.size();){
            if(tasks[i][0] <= curr_time || pq.empty()){
                int enque_time = tasks[i][0];
                int process_time = tasks[i][1];
                string key = to_string(enque_time) + ',' + to_string(process_time);
                
                // pq.push({process_time, {index[key].front(), enque_time}});
                // index[key].pop_front();
                pq.push({process_time, {tasks[i][2], enque_time}});
                
                i++;
             }else{
                auto curr_task = pq.top();
                pq.pop();
                ans.push_back(curr_task.second.first);
                curr_time = max(curr_time, curr_task.second.second) + curr_task.first;
            }
        }
        
        while(!pq.empty()){
            auto curr_task = pq.top();
            pq.pop();
            ans.push_back(curr_task.second.first);
        }
        
        return ans;
    }
};