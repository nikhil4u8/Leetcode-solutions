/*
Ques to ask :
    - Can a course be dependent on more than 1 courses?

Sol :
=> Checking cycles : [TIME - O(N+M) SPACE - O(N+M)]
-> N = no of courses
-> M = size of prerequisites
    - Idea is to check if there is no cycle of dependency, meaning 2 
    courses dependent on each other to complete first.
    - Firstly, we'll create a map to store the mapping of {course, list 
    of courses which are dependent on it}, then in a array (indegree 
    array) store number of dependency of each course, first complete the 
    course with least dependency and decrement the count of courses which 
    are dependent on that course from indegree array, once the indegree of 
    dependent cours == 0, then add it to queue & traverse again.
    - At end, check if all courses are complete or not, if not return 
    false, if yes return true

Follow up :
    - Return order of course completion
        -> Ref : 210. Course Schedule II

*/
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>>mp;
        vector<int>dependency(numCourses, 0);
        //making a graph of dependent elements + count of dendency of 
        //a course
        for(int i=0;i<prerequisites.size();i++){
            int x = prerequisites[i][0], y = prerequisites[i][1];
            dependency[x]++;
            mp[y].push_back(x);
        }

        //check if there is any cycle of not
        //if there is -> return empty vector
        //if not -> do a topological sort  
        //if asked to return the order of course completion also, then 
        //do topological sort
        
        //pushing all independent course in queue
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(dependency[i] == 0) q.push(i);
        }

        //completing all the independent course & removing dependency of
        //other course which are dependent on it & if they also became
        //independent then adding them to list & traversing them
        int zero_dependency = 0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int curr = q.front(); q.pop();
                
                zero_dependency++;

                for(int i=0;i<mp[curr].size();i++){
                    dependency[mp[curr][i]]--;
                    if(dependency[mp[curr][i]] == 0)
                        q.push(mp[curr][i]);
                }
            }
        }

        return zero_dependency == numCourses;
    }
};