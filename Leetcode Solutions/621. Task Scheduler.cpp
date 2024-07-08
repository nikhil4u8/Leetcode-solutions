/*
Ques to ask :
    - Can tasks[i] = 'a'?

Sol :
INTERVIEW BEST APPROACH
=> Priority Queue Method - [TIME - O(NlogN) SPACE - O(N)]
    - First count freq of each char using hashmap then put {char, freq} 
    in max heap
    - Then schedule the task with highest freq first & put the task in 
    waiting queue & assign it a waiting time of current_time + n + 1
    - In each iteration check if front item in queue has finished it's 
    waiting time & then put the item back in heap
    - If there are no item in heap but there are some item in waiting 
    queue then CPU is scheduled to be idle.

COMPETATIVE BEST APPROACH
=> Greedy Mathematics approach - [TIME - O(N) SPACE - O(26)]
    - Firstly, we'll arrange tasks in a "greedy" manner, we'll pick tasks 
    with max frequeny (to minimize idle time) becoz if we arrange other 
    task first then later to arrange task with max freq we'll create more 
    gaps leading to higher idle time.
    - We don't need to actually arrange tasks, we just need to find total 
    idle CPU time.
    - Simply arrange element with max freq, N steps apart (since that much 
    gap is necessary)
    - Now find total number of slots which are empty becoz of arranging 
    max freq element & fill those slots with other task & left over slots 
    needs to fill with idle time.
    - So that's how we find idle time, in end we can simply do idle time 
    + total tasks.

Edge case :
    - When more than one element with same highest freq.
    - There can be other jobs & they don't fit within the space between 
    the blocks. 

Follow up :
    1. If different task has different cooldown period? -> Use heap
    2. Print the arrangement -> Use priority queue method
    3. If 'a...z' are included? -> use hash map to store freq
*/
class Solution {
public:
//BEST APPROACH
//Approach 2 - Using Greedy
//TIME - O(N) SPACE - O(26)
    int leastInterval(vector<char>& tasks, int n) {
        //EX : 3A, 2B, 2C | N = 3
        vector<int>counter(26, 0);
        int max_freq = 0, max_freq_count = 0;

        //to find max freq of element & how many element have max_freq
        for(int i=0;i<tasks.size();i++){
            int idx = tasks[i] - 'A';
            counter[idx]++;
            if(max_freq < counter[idx]){
                max_freq = counter[idx];
                max_freq_count = 1;
            }else if(max_freq == counter[idx]) max_freq_count++;
        }

        //A ? ? ? A ? ? ? A
        int total_gaps = max_freq - 1; //2
        int gap_length = n - (max_freq_count - 1); //3
        int total_empty_slots = total_gaps*gap_length; //6
        int available_task = tasks.size() - max_freq*max_freq_count; //4
        int total_empty_slots_left = max(0, total_empty_slots - available_task); //2

        return total_empty_slots_left + tasks.size(); //9
    }

//Approach 1 - Using heap
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int>freq;
        for(int i=0;i<tasks.size();i++) freq[tasks[i] - 'A']++;
        
        //storing {freq, char}
        priority_queue<pair<int, char>>pq;
        //Waiting queue -> {waiting time, {freq, char}}
        queue<pair<int, pair<int, char>>>q;
        int curr_time = 0;

        for(auto it : freq) pq.push({it.second, it.first});

        while(!pq.empty() || !q.empty()){
            pair<int, char> curr_task;
            //first check if task came out of waiting state or not, if 
            //it did then add it to heap
            if(!q.empty() && q.front().first <= curr_time){
                curr_task = q.front().second; q.pop();
                pq.push(curr_task);
            }
            
            //Finds element with highest freq, and not in waiting state 
            if(!pq.empty()){
                curr_task = pq.top(); pq.pop();
                //if we've more tasks of similar type are left to arrange 
                //then put it in waiting state in queue & decrement freq too
                if(curr_task.first >= 2) 
                    q.push({curr_time + n + 1, {curr_task.first - 1, curr_task.second}});
            }
            curr_time++;
        }

        return curr_time;
    }
};
