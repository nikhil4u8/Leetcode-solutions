/*
Ques to ask :
    - There is no space or any other special char present in log?
    - Can 2 process start/end at same timestamp
    - Can a process have no ending & runs infinitely?
    - This input is invalid ["0:start:0","1:start:2","0:end:4","1:end:6"]?

Sol :
BEST APPROACH
=> Using Stack - [TIME - O(N) SPACE - O(N/2)]
    -Traverse log vector & for each str we need to segregate fun id, 
    start / end, timestamp
    - Use a stack to keep track of order of fun execution.
    - While traversing if "start" of a fun is found, then push it to stack.
    - If "end" of fun is found then top of the stack must be a "start" of 
    same fun, so just subtract timestamps.
    - If there are nested fun call, then we need to keep track of how much 
    time CPU spended in processing nested fun calls, and we need to 
    subtract this time from the parent fun call.
    - Every time a fun call is completely processed i.e ended, then we 
    need to add time it took to process completely to seperate array & 
    return that in end.

Follow up :
    - How to solve if we've N machine instead of 1?
*/
class Solution {
public:
    //returns {id, timestamp, wait_time}
    vector<int> extractData(string log){
        int fun_id = 0, timestamp = 0, count = 0;
        string isStart = "";

        for(int i=0;i<log.length();i++){
            if(log[i] == ':') count++;
            else if(count == 0) fun_id = fun_id*10 + (log[i] - '0');
            else if(count == 1) isStart += log[i];
            else if(count == 2) timestamp = timestamp*10 + (log[i] - '0');
        }

        //if it's a start call, then timestamp > 0, else timestamp < 0
        if(isStart == "start") timestamp *= -1;

        return {fun_id, timestamp, 0};
    }
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        if(logs.size() == 0) return {};

        int wait_time = 0;
        //store {id, timestamp, wait_time}
        stack<vector<int>>sta;
        vector<int>ans(n, 0);

        for(int i=0;i<logs.size();i++){
            auto data = extractData(logs[i]);
            int curr_fun_id = data[0], curr_timestamp = data[1];

          //if curr_timestamp is end timestamp of a fun then it must be 
          //>= 0, then the prev element in stack will be start of same fun
            if(!sta.empty() && curr_timestamp >=0){
                int prev_fun_id = sta.top()[0], prev_timestamp = sta.top()[1];
                //time it's nested child took to execute completely.
                int wait_time = sta.top()[2];

                sta.pop();
                //time diff in ending - starting timestamp
                int process_run_time = curr_timestamp + prev_timestamp + 1;
                //time this process took = time diff - time it's nested 
                //child process took to complete
                ans[curr_fun_id] += process_run_time - wait_time;

                //updating wait time of parent fun call, which is equal 
                //to time it's child took to completely execute
                if(!sta.empty()) sta.top()[2] += process_run_time;
            }
            else sta.push(data);
        }

        return ans;
    }
};