class Solution {
public:
    int racecar(int target) {
        if(target == 0) return 0;
        
        queue<vector<int>>q;
        //position, speed, reverse or accelerate
        // 0 -> acc
        // 1 -> rev
        q.push({0,1,0});
        unordered_map<string,bool>visited;
        visited["0+1"] = true;
        int steps = 0;
        
        while(!q.empty()){
            int size = q.size();
            while(size--){
                vector<int> temp = q.front();
                q.pop();
                
                if(temp[0] == target) return steps;
                int position = temp[0] + temp[1], speed = temp[1]*2;
                
                string key = to_string(position) + '+' + to_string(speed);
                //Accelerate
                if(!visited[key] && abs(target-position) < target - 0){
                    q.push({position, speed, temp[2]});
                    visited[key] = true;
                }
                
                if(temp[1] > 0) speed = -1;
                else speed = 1;
                
                position = temp[0];
                
                key = to_string(position) + '+' + to_string(speed);
                //Reverse
                if(!visited[key] && abs(target - temp[0]) < target){
                    q.push({position, speed, 1});
                    visited[key] = true;
                }
            }
            
            steps++;
        }
        
        return -1;
    }
};